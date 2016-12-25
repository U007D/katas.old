extern crate empty;

#[cfg(test)]
mod tests {
//use super::*;

    #[test]
    fn hello_result() {
        assert!(hello().is_empty() == true);
    }
}
