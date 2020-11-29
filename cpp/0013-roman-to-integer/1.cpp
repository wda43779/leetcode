class Solution {
public:
    int romanToInt(string s) {
        const static struct { char str[3]; int num; } m[] {
            {"M", 1000},
            {"D", 500},
            
            {"CM", 900},
            {"CD", 400},
            {"C", 100},
            
            {"L", 50},
            
            {"XC", 90},
            {"XL", 40},
            {"X", 10},
            
            {"V", 5},
            
            {"IV", 4},
            {"IX", 9},
            {"I", 1},
            
            
        };
        const char *cs = s.c_str();
        int res = 0;
        
        for (auto it : m) {
            if (startsWith(cs, it.str)) {
                while(startsWith(cs, it.str)) {
                    res += it.num;
                    cs += strlen(it.str);
                }
            }
        }
        return res;

    }
private:
    bool startsWith(const char *src, char *head) {
        const char *c1 = src,
                   *c2 = head;
        for (; *c2!='\0' ; c1++, c2++) {
            if (*c1 != *c2) {
                return false;
            }
        }
        return true;
    }
};
