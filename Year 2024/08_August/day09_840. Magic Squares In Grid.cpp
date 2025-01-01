// Problem Link -> https://leetcode.com/problems/magic-squares-in-grid/description/

class Solution {
public:

    bool isMagicGrid(vector<vector<int>>& grid, int startRow, int startCol) {

        unordered_set<int> uniqueNumbers;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int currentNum = grid[startRow + i][startCol + j];
                if (currentNum < 1 || currentNum > 9 || uniqueNumbers.count(currentNum)) {
                    return false;
                } else {
                    uniqueNumbers.insert(currentNum);
                }
            }
        }

        int targetSum = grid[startRow][startCol] + grid[startRow][startCol + 1] + grid[startRow][startCol + 2];
        for (int i = 0; i < 3; i++) {
            if (grid[startRow + i][startCol] + grid[startRow + i][startCol + 1] + grid[startRow + i][startCol + 2] != targetSum) {
                return false;
            }

            if (grid[startRow][startCol + i] + grid[startRow + 1][startCol + i] + grid[startRow + 2][startCol + i] != targetSum) {
                return false;
            }
        }

        if (grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2] != targetSum) {
            return false;
        }

        if (grid[startRow][startCol + 2] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol] != targetSum) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        int magicSquareCount = 0;

        for (int i = 0; i <= numRows - 3; i++) {
            for (int j = 0; j <= numCols - 3; j++) {
                if (isMagicGrid(grid, i, j)) {
                    magicSquareCount++;
                }
            }
        }

        return magicSquareCount;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(1)
