class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int box = 0; box < 9 ;++box) {
            int boxX = box % 3;
            int boxY = box / 3;
            
            bool filled[3][9] = {0};
            for (int idx = 0; idx < 9 ;++idx) {
                int x = idx % 3;
                int y = idx / 3;
                
                char cell[3] = { 0 };
                cell[0] = board[box][idx]; // cell in row box
                cell[1] = board[idx][box]; // cell in column box
                cell[2] = board[boxX * 3 + x][boxY * 3 + y]; // cell in squarebox
                
                for (int i = 0; i < 3; ++i) {
                    if (cell[i] == '.') {
                        continue;
                    } else if (!filled[i][cell[i] - '1']) {
                        filled[i][cell[i] - '1'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
