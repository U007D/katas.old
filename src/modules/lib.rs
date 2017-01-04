pub fn score_game(rolls: &[u8]) -> u16 {
    score_frames(rolls, 1)
}

fn score_frames(rolls: &[u8], frame: u8) -> u16 {
    if frame > 10 {
        0
    } else {
        rolls.iter()
                .take(if rolls.iter()
                        .take(2)
                        .sum::<u8>() == 10 { 3 } else { 2 })
                .sum::<u8>() as u16
            +
                score_frames(&rolls[std::cmp::min(2, rolls.len())..], frame + 1)
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
    assert!(score_game(&[5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]) == 16);
}