// Problem Link -> https://leetcode.com/problems/regions-cut-by-slashes/description/

class Solution {
public:

    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 1)
            return;
        
        grid[row][col] = 1; 

        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            dfs(grid, newRow, newCol);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        int regionsCount = 0;

        vector<vector<int>> expandedGrid(n * 3, vector<int>(n * 3, 0)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    expandedGrid[i * 3][j * 3 + 2] = 1;
                    expandedGrid[i * 3 + 1][j * 3 + 1] = 1;
                    expandedGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    expandedGrid[i * 3][j * 3] = 1;
                    expandedGrid[i * 3 + 1][j * 3 + 1] = 1;
                    expandedGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        for (int row = 0; row < expandedGrid.size(); row++) {
            for (int col = 0; col < expandedGrid[0].size(); col++) {
                if (expandedGrid[row][col] == 0) { 
                    dfs(expandedGrid, row, col);
                    regionsCount += 1;
                }
            }
        }

        return regionsCount;
    }
};




// Time Complexity -> O(rows * cols)
// Space Complexity -> O(rows * cols)
