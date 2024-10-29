// Problem Link -> https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

class Solution {
    int maxMovesHelper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (memo[row][col] != -1) return memo[row][col];
        int max_moves = 0;

        if (row - 1 >= 0 && col + 1 < grid[0].size() && grid[row - 1][col + 1] > grid[row][col]) {
            max_moves = 1 + maxMovesHelper(row - 1, col + 1, grid, memo);
        }

        if (col + 1 < grid[0].size() && grid[row][col + 1] > grid[row][col]) {
            max_moves = max(max_moves, 1 + maxMovesHelper(row, col + 1, grid, memo));
        }

        if (row + 1 < grid.size() && col + 1 < grid[0].size() && grid[row + 1][col + 1] > grid[row][col]) {
            max_moves = max(max_moves, 1 + maxMovesHelper(row + 1, col + 1, grid, memo));
        }
        return memo[row][col] = max_moves;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        int max_moves = 0;

        for (int i = 0; i < rows; ++i) {
            max_moves = max(max_moves, maxMovesHelper(i, 0, grid, memo));
        }

        return max_moves;
    }
};
