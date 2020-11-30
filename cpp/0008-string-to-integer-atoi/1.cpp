class Solution {
    int impl(char const* s) {
        // skipping spaces
        for(; *s == ' '; ++s) { }


        // meet first none space character
        int sign = 1;
        if (*s == '-') {
            sign = -1;
            ++s;
        } else if (*s == '+') {
            sign = 1;
            ++s;
        } else if (*s < '0' || '9' < *s) return 0;

        int res = 0;
        while('0' <= *s && *s <= '9') {
            int tail = *s - '0';

            // dealing with limits
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && tail > 7)
                return sign == 1 ? INT_MAX : INT_MIN;

            res = res * 10 + tail;
            ++s;
        }
        return sign * res;
    }
public:
    int myAtoi(string s) {
        return impl(s.c_str());
    }
};
