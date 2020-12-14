class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l1 = n / 2;
        int l2 = n - l1;
        int temp = 0;
        
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                temp = matrix[i][j];
                swap(temp, matrix[j][n-i-1]);
                swap(temp, matrix[n-i-1][n-j-1]);
                swap(temp, matrix[n-j-1][i]);
                swap(temp, matrix[i][j]);
            }
        }
    }
};
