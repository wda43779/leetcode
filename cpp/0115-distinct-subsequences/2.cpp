class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> mem;
        // mem[i][j] is nums of distinct found t[i] in s[]

        // initializing
        for (int i = 0; i <= t.size(); ++i) {
            mem.push_back(vector<long>());
            for (int j = 0; j <= s.size(); ++j) {
              mem[i].push_back(i == 0);
            }
        }
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                mem[i+1][j+1] = mem[i+1][j] + (s[j] == t[i] ? mem[i][j] : 0);
            }
        }
        return mem[t.size()][s.size()];
    }
};
