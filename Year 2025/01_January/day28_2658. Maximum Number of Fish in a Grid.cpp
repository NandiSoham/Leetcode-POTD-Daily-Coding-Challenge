// Problem Link -> https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfsFunc(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) {
            return 0;
        }

        int fishCollected = grid[row][col];
        grid[row][col] = 0;
        for (vector<int>& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            fishCollected += dfsFunc(newRow, newCol, grid);
        }

        return fishCollected;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxFishCollected = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] > 0){
                    maxFishCollected = max(maxFishCollected, dfsFunc(row, col, grid));
                }
            }
        }

        return maxFishCollected;
    }
};



// Time Complexity -> O(rows * cols)
// Space Complexity -> O(rows * cols)

// =========================================================================================
