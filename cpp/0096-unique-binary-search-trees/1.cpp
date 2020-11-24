class Solution {
public:
    int numTrees(int n) {
        int mem[20] = {1, 1};
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int l = mem[j - 1];
                int r = mem[i - j];
                mem[i] += l * r;
            }
        }
        return mem[n];
    }
};
