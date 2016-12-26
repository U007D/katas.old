fn game_score(rolls: &Vec<u8>) -> u16 {
    0
}

#[test]
fn gutterball_game() {
    let result = game_score(&vec![0u8; 10]);
    assert!(result == 0);
}