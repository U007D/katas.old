/* node/BowlingGameFP.js
Version 1.0
Author: Boris GBAHOUE
Comments: Implementation of Bowling Game kata (http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata)

Release notes:
    v1.0: Benchmark declarative vs FP attempt #1 vs FP attempt #2
*/

// =======================================================================
// BASE SETUP
// =======================================================================
const debug     = require('debug')('DEBUG');

// =======================================================================
// CONSTRUCTOR
// =======================================================================
/**
 * @constructor
 */
function BowlingGameBench() {
    // empty
}

// =======================================================================
// PUBLIC METHODS
// =======================================================================
/**
 * FP attempt #4
 * @param {[int]} rolls 
 */
BowlingGameBench.score_v4 = function(rolls, frame = 1) {
    if ((rolls == null) || (rolls.length == 0) || (frame > 10)) return 0;

    return rolls.slice(0, ( rolls[0]+rolls[1] | 0 ) >= 10 ? 3 : 2)
                .reduce( (total, val) => (total+val) )
           +
           BowlingGameBench.score_v4(rolls.slice(rolls[0] == 10 ? 1 : 2), frame+1);
}

/**
 * FP attempt #3
 * @param {[int]} rolls 
 */
BowlingGameBench.score_v3 = function(rolls) {
    return rolls.slice()
            .reduce(
                (totalScore, value, index, array) => {
                    const $isLastFrame = (array.length - index - 1) <= 2;
                    let $frameLength = $isLastFrame ? 3 : 2;

                    if (array[index] == 10) {
                        totalScore += 10 + (array[index+1] | 0) + (array[index+2] | 0);
                        if (!$isLastFrame) $frameLength = 1;
                    } else if ((array[index] + array[index+1]) == 10) {
                        totalScore += 10 + (array[index+2] | 0);
                    } else {
                        totalScore += array[index] + (array[index+1] | 0);
                    }

                    array.splice(index, $frameLength-1);
                    return totalScore;
                }, 
                0
            );
}

/**
 * FP attempt #2
 * @param {[int]} rolls 
 */
BowlingGameBench.score_v2 = function(rolls) {
    return rolls.slice() // create shallow copy since splitIntoFrames modifies the array upon which it is called
            .reduce(getFrameScore, 0);
}

/**
 * @param {[int]} rolls 
 */
BowlingGameBench.score_v1 = function(rolls) {
    return rolls.slice() // create shallow copy since splitIntoFrames modifies the array upon which it is called
        .reduce(splitIntoFrames, []) // array of [roll1, roll2, roll3], possibly including 'indefined' values
        .map(replaceUndefinedValuesByZero) // array of [roll1, roll2, roll3]
        .reduce(computeTotalScore, 0);
}

// =======================================================================
// PRIVATE METHODS
// =======================================================================
// ATTEMPT #1
// =======================================================================
/**
 * Reduce function used to replace an [int] into the corresponding [[int]]
 */
function splitIntoFrames(accumulator, value, index, array) {
    let $frameIndex = accumulator.length+1;

    if ($frameIndex == 10) {
        accumulator.push([value, array[index+1], array[index+2]]); // possibly adding undefined values
        array.splice(index, 2); // remove all remaining entries from array

    } else if (isStrike(array, index)) { // array[index] == 10
        accumulator.push([value, 0, 0]);

    } else { // spare or normal frame
        accumulator.push([value, array[index+1], 0]);
        array.splice(index, 1); // skip next entry by removing it from the array
    }

    return accumulator;
}

function replaceUndefinedValuesByZero(array) {
    return array.map( (value) => ( (value === undefined) ? 0 : value ) );
}

/**
 * Reduce function used to transform [roll1, roll2, roll3] into a score
 * 
 * @param {Number} score : accumulator
 * @param {[Number]} frame
 */
function computeTotalScore(score, frame, index, array) {
    debug("Processing frame %j, current score = %d", frame, score);
    if ((array[index+1] !== undefined) && isStrike(frame)) { // frame[0] == 10
        if (isStrike(array[index+1])) {
            return ((index+1) == (array.length-1)) ?
                        score + 10 + array[index+1][0] + array[index+1][1] :
                        score + 10 + array[index+1][0] + array[index+2][0]; 
        } else {
            return score + (10 + array[index+1][0] + array[index+1][1]);
        }
    } else if ((array[index+1] !== undefined) && isSpare(frame)) { // frame[0] + frame[1] == 10
        return score + (10 + array[index+1][0]);
    } else {
        return score + computeFrameScore(frame);
    }
}

/**
 * Reduce function to compute the score of a frame
 * 
 * @param {[Number]} frame
 */
function computeFrameScore(frame) {
    return frame.reduce( (score, value) => (score+value), 0 );
}

// ATTEMPT #2
// =======================================================================
/**
 * Reduce function used to calculate the next frame score and slice the array to the next frame
 */
function getFrameScore(totalScore, value, index, array) {
    const $isLastFrame = (array.length - index - 1) <= 2; // 2 or 3 rolls left
    let $frameLength = $isLastFrame ? 3 : 2; // default frame length

    debug("Current score = %d => Processing value = %s, index = %d, array = %j (last frame = %s)", totalScore, value, index, array, $isLastFrame);

    if (isStrike(array, index)) {
        totalScore += 10 + (array[index+1] | 0) + (array[index+2] | 0); // '| 0' deals with undefined values (when index is outside of array)
        if (!$isLastFrame) $frameLength = 1;
    } else if (isSpare(array, index)) {
        totalScore += 10 + (array[index+2] | 0);
    } else {
        totalScore += (array[index] | 0) + (array[index+1] | 0);
    }

    // Remove current frame
    array.splice(index, $frameLength-1); // '$frameLength-1' since index will be incremented by reduce logic

    return totalScore;
}

// COMMON STUFF
// =======================================================================
function isStrike(array, index=0) {
    return (array[index] == 10);
}

function isSpare(array, index=0) {
    return ((array[index] + array[index+1]) == 10);
}

module.exports = BowlingGameBench;