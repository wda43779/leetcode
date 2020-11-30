class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int res = 0;
        
        while(x != 0) {
            int xtail = x % 10;
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && xtail > 7) return 0;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && xtail < -8) return 0;
            res = res*10 + xtail;
            x = x / 10;
        }

        return res;
    }
};
