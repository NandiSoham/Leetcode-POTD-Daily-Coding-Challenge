// Problem Link -> https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows;
    int cols;

    void exploreIsland(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || grid[row][col] == 0)
            return;
        
        visited[row][col] = true; 

        for (auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            exploreIsland(grid, newRow, newCol, visited);
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == 1) { 
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    } 

    int minDays(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int initialIslandCount = countIslands(grid);

        if (initialIslandCount > 1 || initialIslandCount == 0) {
            return 0;
        } else {

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    if (grid[row][col] == 1) {
                        grid[row][col] = 0; 
						
                        int currentIslandCount = countIslands(grid);
						
                        grid[row][col] = 1; 
                        if (currentIslandCount > 1 || currentIslandCount == 0)
                            return 1;
                    }
                }
            }
        }

        return 2;
    }
};



//Time Complexity : O((m*n)^2)
//Space Complexity : O(m*n)
