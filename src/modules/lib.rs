fn game_score(rolls: &Vec<u8>) -> u16 {
    rolls.iter().map(|el| { *el as u16 }).sum()
}

#[test]
fn gutterball_game() {
    let result = game_score(&vec![0u8; 10]);
    assert!(result == 0);
}

#[test]
fn one_ball_game() {
    let result = game_score(&vec![1u8; 20]);
    assert!(result == 20);
}