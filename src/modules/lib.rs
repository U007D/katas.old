fn game_score(rolls: &[u8]) -> u16 {
    frame_score(rolls, 1)
}

fn frame_score(rolls: &[u8], frame: u8) -> u16 {

    if frame > 10 || rolls.is_empty() {
        0
    }
    else {
        rolls.iter()
            .take(if rolls[0] + rolls[1] == 10 { 3 } else { 2 })
            .fold(0u16, | sum, el | sum + *el as u16)
        + frame_score(&rolls[2..], frame + 1)
    }
}

#[test]
fn gutterball_game() {
    let result = game_score(&[0u8; 10]);
    assert!(result == 0);
}

#[test]
fn one_ball_game() {
    let result = game_score(&vec![1u8; 20]);
    assert!(result == 20);
}

#[test]
fn spare_followed_by_3_rest_gutterball_game() {
    let result = game_score(&vec![5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
    assert!(result == 16);
}