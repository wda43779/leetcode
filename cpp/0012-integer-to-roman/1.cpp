class Solution {
public:
    string intToRoman(int num) {
        const static struct {int num; char str[3];} m[13] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        };
        string res;
        
        for (auto &it : m) {
            while (num >= it.num) {
                num -= it.num;
                res += it.str;
            }
            if (num == 0) break;
        }
        return res;
    }
};
