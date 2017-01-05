/* node/BowlingGameFP.js
Version 4.0
Author: Boris GBAHOUE
Comments: Implementation of Bowling Game kata (http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata)

Release notes:
    v4.0: Attempt #4
        - inspired by Brad's attempt #15
    v3.0: Attempt #3
        - since reduce() body
    v2.0: Attempt #2
        - merged 'splitIntoFrames' logic with score calculation
    v1.0: Attempt #1 using Functional Programming principle
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
function BowlingGameFP() {
    // empty
}

// =======================================================================
// PUBLIC METHODS
// =======================================================================
/**
 * @param {[Number]} rolls 
 */
BowlingGameFP.score = function(rolls, frame = 1) {
    if ((rolls == null) || (rolls.length == 0) || (frame > 10)) return 0;

    return rolls.slice(0, ( rolls[0]+rolls[1] | 0 ) >= 10 ? 3 : 2)
                .reduce( (total, val) => (total+val) )
           +
           BowlingGameFP.score(rolls.slice(rolls[0] == 10 ? 1 : 2), frame+1);
}

module.exports = BowlingGameFP;