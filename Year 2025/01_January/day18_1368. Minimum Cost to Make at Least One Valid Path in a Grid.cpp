// Problem Link -> https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

// ======================================= Approach - 1 (This will give TLE) ====================================

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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        minHeap.push({0, 0, 0});
        cost[0][0] = 0;

        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int currentCost = current[0];
            int currentRow = current[1];
            int currentCol = current[2];

            if (cost[currentRow][currentCol] < currentCost) {
                continue;
            }

            for (int dirIndex = 0; dirIndex <= 3; dirIndex++) {
                int newRow = currentRow + directions[dirIndex][0];
                int newCol = currentCol + directions[dirIndex][1];

                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
                    int gridDirection = grid[currentRow][currentCol];
                    int directionCost = ((gridDirection - 1 != dirIndex) ? 1 : 0);

                    int updatedCost = currentCost + directionCost;

                    if (updatedCost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = updatedCost;
                        minHeap.push({updatedCost, newRow, newCol});
                    }
                }
            }
        }
        return cost[rows - 1][cols - 1];
    }
};



// Time Complexity -> O((m*n) * log(m*n))
// Space Complexity -> O(m*n)

// =========================================================================================
