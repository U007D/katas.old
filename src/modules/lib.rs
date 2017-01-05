
fn hello() -> String {
    format!("Hello, {}-bit world!", std::usize::MAX)
}

#[test]
fn hello_result() {
    assert!(hello().is_empty() == false);
}