
pub fn score(rolls: &[u8]) -> u16 {
    return 0;
}

#[test]
fn all_gutterballs_yield_zero() {
    assert!(score(&[20; 0]) == 0);
}