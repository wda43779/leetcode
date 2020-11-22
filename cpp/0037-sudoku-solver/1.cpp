class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        _solveSudoku(board);
    }
private:
    bool _solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int guess = 1; guess <= 9; ++guess) {
                        // validing guess
                        if (!checkCell(board, i, j, guess + '0')) {continue;}
                        board[i][j] = guess + '0';
                        if (_solveSudoku(board)) {return true;}
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkCell(vector<vector<char>>& board, int i, int j, char guess) {
        for (int k = 0; k < 9; k++) {
            if (guess == board[i][k] ||
            guess == board[k][j] ||
            guess == board[i - i % 3 + k % 3][j - j % 3 + k / 3]
            ) {
                return false;
            }
        }  
        return true;
    }
};
