
pub fn score(rolls: &[u8]) -> u16 {
    return rolls.iter()
                .map(|el| *el as u16)
                .sum();
}

#[test]
fn all_gutterballs_yield_zero() {
    assert!(score(&[20; 0]) == 0);
}

#[test]
fn all_one_balls_yields_20() {
    assert!(score(&[20; 1]) == 20);
}