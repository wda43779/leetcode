const b: [&[u8]; 10] = [b"",b"",b"abc",b"def",b"ghi",b"jkl",b"mno", b"pqrs", b"tuv", b"wxyz"];
fn letter_combinations_impl(digits: &[u8]) -> Vec<String> {
    let l = digits.len();
    if l == 0 {return vec![];}

    let left = &digits[0..l-1];
    let left = letter_combinations_impl(left);
    let right = (digits[l-1] - b'0') as usize;

    if l == 1 {
        return Vec::from(b[right]).iter().map(|&num| {
            let mut ret = String::new();
            ret.push(num as char);
            ret
        }).collect();
    }
    
    let mut ret = Vec::new();
    for &c in b[right].iter() {
        for s in left.iter() {
            let mut o = s.to_owned();
            o.push(c as char);
            ret.push(o)
        }
    }
    ret
}

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        letter_combinations_impl(digits.as_bytes())
    }
}
