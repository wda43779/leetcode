class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        
        int mirror = 0;
        while(mirror < x) {
            mirror = mirror * 10 + x % 10;
            x = x /10;
        }

        return x == mirror || x == mirror / 10;
    }
};
