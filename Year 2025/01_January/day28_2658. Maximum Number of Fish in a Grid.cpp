// Problem Link -> https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

// ======================================= Approach - 1 (DFS) ====================================

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

// ===============================================================================================


// ======================================= Approach - 2 (BFS) ====================================

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfsFunc(int startRow, int startCol, vector<vector<int>>& grid) {
        queue<pair<int, int>> cellQueue;
        cellQueue.push({startRow, startCol});
        int totalFish = grid[startRow][startCol];
        grid[startRow][startCol] = 0;

        while (!cellQueue.empty()) {
            int currentRow = cellQueue.front().first;
            int currentCol = cellQueue.front().second;
            cellQueue.pop();

            for (auto& direction : directions) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];

                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] > 0) {
                    cellQueue.push({newRow, newCol});
                    totalFish += grid[newRow][newCol];
                    grid[newRow][newCol] = 0;
                }
            }
        }

        return totalFish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int maxFishCollected = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 0) { 
                    maxFishCollected = max(maxFishCollected, bfsFunc(row, col, grid));
                }
            }
        }

        return maxFishCollected;
    }
};



// Time Complexity -> O(rows * cols)
// Space Complexity -> O(rows * cols)

// =========================================================================================
