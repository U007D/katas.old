pub mod bowling {
    fn score(rolls: &[u8], frame_number: Option<u8>) -> u16 {
        let frame = frame_number.unwrap_or(1);
        if frame > 10 {
            0
        } else {
            rolls.iter()
                .take(if rolls[0]+rolls[1] >= 10 { 3 } else { 2 })
                .sum::<u8>() as u16
            +
            score(rolls.split_at(if rolls[0] == 10 { 1 } else { 2 } ).1, Some(frame+1))
        }
    }

    #[test]
    fn all_gutterballs() {
        let game = [0; 20];
        let result = score(&game, None);
        assert!(result == 0);
    }

    #[test]
    fn all_one_balls() {
        let game = [1; 20];
        let result = score(&game, None);
        assert!(result == 20);
    }

    #[test]
    fn spare_3_and_gutter_balls() {
        let game = [5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
        let result = score(&game, None);
        assert!(result == 16);
    }

    #[test]
    fn strike_3_4_and_gutter_balls() {
        let game = [10, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
        let result = score(&game, None);
        assert!(result == 24);
    }

    #[test]
    fn all_strikes() {
        let game = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10];
        let result = score(&game, None);
        assert!(result == 300);
    }

    #[test]
    fn uncle_bob() {
        let game = [1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6];
        let result = score(&game, None);
        assert!(result == 133);
    }
}