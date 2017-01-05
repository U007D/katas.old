/* node/Game.js
Version 1.0
Author: Boris GBAHOUE
Comments: Game class implementation

Release notes:
    v1.0:
        - creation
*/

// =======================================================================
// BASE SETUP
// =======================================================================

// =======================================================================
// CONSTRUCTOR
// =======================================================================
/**
 * @constructor
 */
function Game(rolls) {
    if (Array.isArray(rolls)) {
        this._rolls = rolls.slice();
        this._currentRoll = this._rolls.length;
    } else {
        this.reset();
    }
}

// =======================================================================
// PUBLIC METHODS
// =======================================================================
Game.prototype.reset = function() {
    this._rolls = [];
    this._currentRoll = 0;
}

Game.prototype.roll = function(pins) {
    this._rolls[this._currentRoll++] = pins;
}

Game.prototype.rollMany = function(nbRolls, pins) {
    for (let i = 0; i < nbRolls; i++)
        this._rolls[this._currentRoll++] = pins;
}

Game.prototype.rolls = function() {
    return this._rolls.slice();
}

Game.prototype.toString = function() {
    return util.format("Rolls = %j", this._rolls);
}

module.exports = Game;