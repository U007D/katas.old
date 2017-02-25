pub fn score_game(rolls: &[u8]) -> u16 {
    score_frames(rolls, 1)
}

fn frame_score(rolls: &[u8], frame: u8) -> u16 {

    match frame > 10 || rolls.is_empty() {
        true => 0,
        false => rolls.iter()
                      .take(match rolls[0] + rolls[1] >= 10 { true => 3, false => 2 })
                      .fold(0u16, | sum, &el | sum + el as u16)
            + frame_score(&rolls[match rolls[0] == 10 { true => 1, false => 2 }..], frame + 1)
    }
}

#[test]
fn all_gutterballs_yield_zero() {
    assert!(score_game(&[0; 20]) == 0);
}

#[test]
fn all_one_balls_yields_20() {
    assert!(score_game(&[1; 20]) == 20);
}

#[test]
fn spare_then_3_followed_by_gutterballs_yields_16() {
    assert!(score_game(&[5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]) == 16);
}

#[test]
fn strike_then_3_then_4_followed_by_gutterballs_yields_24() {
    assert!(score_game(&[10, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]) == 24);
}

#[test]
fn all_strikes_yields_300() {
    assert!(score_game(&[10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]) == 300);
}
