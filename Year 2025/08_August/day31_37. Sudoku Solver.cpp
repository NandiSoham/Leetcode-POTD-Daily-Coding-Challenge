// Problem Link -> https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, i, j, digit)) {
                            board[i][j] = digit;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == digit || board[k][col] == digit)
                return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit)
                    return false;
            }
        }
        return true;
    }
};
