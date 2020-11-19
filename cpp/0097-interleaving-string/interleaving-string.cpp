class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        
        bool mem[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0)
                    mem[i][j] = true;
                else if (i == 0)
                    mem[i][j] = mem[i][j-1] && s2[j-1] == s3[i+j-1];
                else if (j == 0)
                    mem[i][j] = mem[i-1][j] && s1[i-1] == s3[i+j-1];
                else
                    mem[i][j] = (mem[i][j-1] && s2[j-1] == s3[i+j-1]) ||
                 (mem[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
            
        return mem[m][n];
    }
};
