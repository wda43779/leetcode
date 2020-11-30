impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<u8> = vec![];
    
        for c in s.as_bytes() {
            match c {
                b'(' => stack.push(b')'),
                b'[' => stack.push(b']'),
                b'{' => stack.push(b'}'),
                _ => {
                    if stack.len() == 0 { return false; }
                    let top = stack.pop().unwrap();
                    if top != *c { return false; }
                },
            }
        }

        stack.len() == 0
    }
}
