class Solution {
public:
    int numDistinct(string s, string t) {
        int res = 0;
        vector<vector<int>> mem;
        for (int i = 0; i < t.size(); ++i) {
            mem.push_back(vector<int>());
            for (int j = 0; j < s.size(); ++j) {
                if (t[t.size() - i - 1] == s[j]) {
                    if (i == 0) { mem[i].push_back(1); }
                    else { mem[i].push_back(mysum(mem[i-1], j + 1, s.size())); }
                } else { mem[i].push_back(0); }
            }
        }
        return mysum(mem[t.size() - 1], 0, s.size());
    }
private:
    int mysum(vector<int> &vec, int min, int max) {
        long res = 0;
        for (int i = min; i < max; ++i) {
            res += vec[i];
        }
        return res;
    }
};
