// Problem Link -> https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

class Solution {
public:
    void markGuardedCells(int guardRow, int guardCol, vector<vector<int>>& grid) {
        for (int row = guardRow - 1; row >= 0; row--) {
            if (grid[row][guardCol] == 2 || grid[row][guardCol] == 3) {
                break;
            }
            grid[row][guardCol] = 1; 
        }

        for (int row = guardRow + 1; row < grid.size(); row++) {
            if (grid[row][guardCol] == 2 || grid[row][guardCol] == 3) {
                break;
            }
            grid[row][guardCol] = 1; 
        }

        for (int col = guardCol - 1; col >= 0; col--) {
            if (grid[guardRow][col] == 2 || grid[guardRow][col] == 3) {
                break;
            }
            grid[guardRow][col] = 1; 
        }

        for (int col = guardCol + 1; col < grid[0].size(); col++) {
            if (grid[guardRow][col] == 2 || grid[guardRow][col] == 3) {
                break;
            }
            grid[guardRow][col] = 1; 
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0)); 

        for (vector<int>& guard : guards) {
            int row = guard[0];
            int col = guard[1];
            grid[row][col] = 2;
        }

        for (vector<int>& wall : walls) {
            int row = wall[0];
            int col = wall[1];
            grid[row][col] = 3; 
        }

        for (vector<int>& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];
            markGuardedCells(guardRow, guardCol, grid);
        }

        int unguardedCount = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) { 
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};
