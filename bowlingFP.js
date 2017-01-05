const assert        = require('assert');
const BowlingGame   = require('./BowlingGameBench');
const Game          = require('./Game');

console.log("================== ATTEMPT #1 ==================");
runTests(BowlingGame.score_v1);

console.log("================== ATTEMPT #2 ==================");
runTests(BowlingGame.score_v2);

console.log("================== ATTEMPT #3 ==================");
runTests(BowlingGame.score_v3);

console.log("================== ATTEMPT #4 ==================");
runTests(BowlingGame.score_v4);

function runTests(scoreFn, stop = false) {
    console.time("Global test");

    let $score;
    let $id = "Gutter game";
    console.time($id);
    $score = scoreFn(getGutterGame());
    console.timeEnd($id);
    assert.equal($score, 0);
    // console.log("Gutter game ok\n");

    $id = "All ones game";
    console.time($id);
    $score = scoreFn(getAllOnesGame());
    console.timeEnd($id);
    assert.equal($score, 20);
    // console.log("All ones game ok\n");

    $id = "One spare game";    
    console.time($id);
    $score = scoreFn(getOneSpareGame());
    console.timeEnd($id);
    assert.equal($score, 16); // (10+3) + (3+0) + 0 ... + 0
    // console.log("One spare game ok\n");

    $id = "One strike game";    
    console.time($id);
    $score = scoreFn(getOneStrikeGame());
    console.timeEnd($id);
    assert.equal($score, 24); // (10+3+4) + (3+4) + 0 ... + 0
    // console.log("One strike game ok\n");

    $id = "Perfect game";    
    console.time($id);
    $score = scoreFn(getPerfectGame());
    console.timeEnd($id);
    assert.equal($score, 300); 
    // console.log("Perfect game ok\n");

    let rolls = [1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6];
    $id = "Uncle Bob's game";    
    console.time($id);
    $score = scoreFn(rolls);
    console.timeEnd($id);
    // console.log("Textbook game = %j => score = %d", rolls, $score);
    assert.equal($score, 133);
    // console.log("Textbook game ok\n");

    console.timeEnd("Global test");
}

// =======================================================================
// PRIVATE METHODS
// =======================================================================
function getGutterGame() {
    let game = new Game();
    game.rollMany(20, 0);
    return game.rolls();
}

function getAllOnesGame() {
    let game = new Game();
    game.rollMany(20, 1);
    return game.rolls();
}

function getOneSpareGame() {
    let game = new Game();
    game.roll(5);
    game.roll(5);
    game.roll(3);
    game.rollMany(17,0);
    return game.rolls();
}

function getOneStrikeGame() {
    let game = new Game();
    game.roll(10);
    game.roll(3);
    game.roll(4);
    game.rollMany(16, 0);
    return game.rolls();
}

function getPerfectGame() {
    let game = new Game();
    game.rollMany(12, 10);
    return game.rolls();
}
