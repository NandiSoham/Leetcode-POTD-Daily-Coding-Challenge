// Problem Link -> https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int DFSfunc(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int currentCost){
        if(x == rows - 1 && y == cols - 1){
            return currentCost;
        }

        visited[x][y] = true;
        int minCost = INT_MAX;

        for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
            int newX = x + directions[dirIndex][0];
            int newY = y + directions[dirIndex][1];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                int arrowDirection = grid[x][y] - 1; 
                int changeCost = (arrowDirection != dirIndex) ? 1 : 0; 
                int newCost = currentCost + changeCost;

                minCost = min(minCost, DFSfunc(newX, newY, grid, visited, newCost));
            }
        }

        visited[x][y] = false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        return DFSfunc(0, 0, grid, visited, 0);
    }
};



// Time Complexity -> O(4^(m*n))
// Space Complexity -> O(m*n)

// =========================================================================================
