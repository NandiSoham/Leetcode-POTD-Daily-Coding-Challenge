// Problem Link -> https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

class Solution {
public:
    #define CellInfo pair<int, pair<int, int>>
    vector<vector<int>> movementDirections = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minObstacleCount(rows, vector<int>(cols, INT_MAX));
        minObstacleCount[0][0] = 0;

        priority_queue<CellInfo, vector<CellInfo>, greater<CellInfo>> priorityQueue;
        priorityQueue.push({0, {0, 0}});

        while (!priorityQueue.empty()) {
            auto current = priorityQueue.top();
            priorityQueue.pop();

            int currentObstacleCount = current.first;
            int currentRow = current.second.first;
            int currentCol = current.second.second;

            for (auto& direction : movementDirections) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];

                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    continue;
                }

                int weight = (grid[newRow][newCol] == 1) ? 1 : 0;

                if (currentObstacleCount + weight < minObstacleCount[newRow][newCol]) {
                    minObstacleCount[newRow][newCol] = currentObstacleCount + weight;
                    priorityQueue.push({currentObstacleCount + weight, {newRow, newCol}});
                }
            }
        }

        return minObstacleCount[rows - 1][cols - 1];
    }
};
