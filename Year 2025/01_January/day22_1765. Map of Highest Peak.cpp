// Problem Link -> https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
public:
    typedef pair<int, int> Cell;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        queue<Cell> bfsQueue;
        vector<vector<int>> heights(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    bfsQueue.push({i, j});
                }
            }
        }

        while (!bfsQueue.empty()) {
            Cell currElement = bfsQueue.front();
            bfsQueue.pop();
            int currRow = currElement.first;
            int currCol = currElement.second;

            for (auto& dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols && heights[newRow][newCol] == -1) {
                        heights[newRow][newCol] = heights[currRow][currCol] + 1;
                        bfsQueue.push({newRow, newCol});
                }
            }
        }

        return heights;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(m*n)
