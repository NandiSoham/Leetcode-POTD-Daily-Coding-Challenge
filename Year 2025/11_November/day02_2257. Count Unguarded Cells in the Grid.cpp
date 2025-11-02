// Problem Link -> https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int direction) {
        if (row < 0 || col < 0 || row >= rows || col >= cols ||
            grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }

        grid[row][col] = 3;

        if (direction == 1) {
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) {
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) {
            dfs(grid, row, col - 1, rows, cols, direction);
        } else {
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        for (const auto& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1;
        }

        for (const auto& wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2;
        }

        for (const auto& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow - 1, guardCol, rows, cols, 1);
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2);
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3);
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4);
        }

        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};


// Time Complexity -> O(rows * cols)
// Space Complexity -> O(rows * cols)
