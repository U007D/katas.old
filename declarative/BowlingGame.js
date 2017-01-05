/* node/BowlingGame.js
Version 1.0
Author: Boris GBAHOUE
Comments: Implementation of Bowling Game kata (http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata)

Release notes:
    v1.0:
        - creation from UncleBob's solution
*/

// =======================================================================
// BASE SETUP
// =======================================================================
const util      = require('util');

// =======================================================================
// CONSTRUCTOR
// =======================================================================
/**
 * @constructor
 */
function BowlingGame() {
    this.reset();
}

// =======================================================================
// PUBLIC METHODS
// =======================================================================
BowlingGame.prototype.reset = function() {
    this.rolls = [];
    this.currentRoll = 0;
}

BowlingGame.prototype.roll = function(pins) {
    this.rolls[this.currentRoll++] = pins;
}

BowlingGame.prototype.rollMany = function(nbRolls, pins) {
    for (let i = 0; i < nbRolls; i++)
        this.rolls[this.currentRoll++] = pins;
}

BowlingGame.prototype.score = function() {
    let score = 0;
    let frameIndex = 0;
    for (let frame = 0; frame < 10; frame++) {
      if (isStrike.call(this, frameIndex)) {
        score += 10 + strikeBonus.call(this, frameIndex);
        frameIndex++;
      } else if (isSpare.call(this, frameIndex)) {
        score += 10 + spareBonus.call(this, frameIndex);
        frameIndex += 2;
      } else {
        score += sumOfBallsInFrame.call(this, frameIndex);
        frameIndex += 2;
      }
    }
    return score;
}

BowlingGame.prototype.toString = function() {
    return util.format("Score = %d\nRolls = %j", this.score(), this.rolls);
}

// =======================================================================
// PRIVATE METHODS
// =======================================================================
function isStrike(frameIndex) {
    return this.rolls[frameIndex] == 10;
}

function sumOfBallsInFrame(frameIndex) {
    return this.rolls[frameIndex] + this.rolls[frameIndex+1];
}

function spareBonus(frameIndex) {
    return this.rolls[frameIndex+2];
}

function strikeBonus(frameIndex) {
    return this.rolls[frameIndex+1] + this.rolls[frameIndex+2];
}

function isSpare(frameIndex) {
    return this.rolls[frameIndex] + this.rolls[frameIndex+1] == 10;
}

module.exports = BowlingGame;