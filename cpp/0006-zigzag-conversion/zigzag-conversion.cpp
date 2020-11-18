class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        std::string rows[numRows];

        auto row = 0;
        for (auto i = 0; i < s.size(); ++i) {
            rows[row].push_back(s[i]);
            if (i % ((numRows - 1) * 2) < numRows - 1) {
                ++row;
            } else {
                -- row;
            }
        }

        std::string res;
        for (auto &it : rows) {
            res.append(it);
        }
        return res;
    }
};
