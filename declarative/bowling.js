const assert    = require('assert');
const Game      = require('./BowlingGame');

function testGutterGame(game) {
    game.rollMany(20, 0);
    assert.equal(0, game.score());
}

function testAllOnes(game) {
    game.rollMany(20, 1);
    assert.equal(20, game.score());
}

function testOneSpare(game) {
    rollSpare(game);
    game.roll(3);
    game.rollMany(17,0);
    assert.equal(16,game.score()); // (10+3) + (3+0) + 0 ... + 0
}

function testOneStrike(game) {
    rollStrike(game);
    game.roll(3);
    game.roll(4);
    game.rollMany(16, 0);
    assert.equal(24, game.score()); // (10+3+4) + (3+4) + 0 ... + 0
}

function testPerfectGame(game) {
    game.rollMany(12, 10);
    assert.equal(300, game.score());
}

function rollStrike(g) {
    g.roll(10);
}

function rollSpare(g) {
    g.roll(5);
    g.roll(5);
}

let g = new Game();
testGutterGame(g);
console.log("Game #1 => Gutter\n%s", g);
g.reset();

testAllOnes(g);
console.log("Game #2 => All ones\n%s", g);
g.reset();

testOneSpare(g);
console.log("Game #3 => One Spare\n%s", g);
g.reset();

testOneStrike(g);
console.log("Game #4 => One Strike\n%s", g);
g.reset();

testPerfectGame(g);
console.log("Game #5 => Perfect\n%s", g);
g.reset();

let rolls = [1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6];
rolls.slice().reduce(splitIntoFrames,[])

let rolls2 = [1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 7];


rolls.slice().reduce(splitIntoFrames, []).map(replaceUndefinedValuesByZero).reduce(computeTotalScore, 0)