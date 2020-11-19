class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        
        int counts[26] = { 0 };
        for (auto &ch : s1) {
            ++counts[ch - 'a'];
        }
        for (auto &ch : s2) {
            --counts[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (counts[i] != 0) {
                return false;
            }
        }
        
        int len = s1.size();
        for (int i = 1; i < len; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                 && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(len - i))
                 && isScramble(s1.substr(i), s2.substr(0, len - i))) {
                return true;
            }
        }
        return false;
    }
};
