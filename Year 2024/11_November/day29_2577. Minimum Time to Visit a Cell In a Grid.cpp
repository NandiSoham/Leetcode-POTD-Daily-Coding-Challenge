// Problem Link -> https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

class Solution {
public:
    vector<vector<int>> movementDirections{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define CellInfo pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<CellInfo, vector<CellInfo>, greater<CellInfo>> priorityQueue;
        
        priorityQueue.push({grid[0][0], {0, 0}});
        
        while (!priorityQueue.empty()) {
            int currentTime = priorityQueue.top().first;
            int currentRow = priorityQueue.top().second.first;
            int currentCol = priorityQueue.top().second.second;
            priorityQueue.pop();
            
            if (currentRow == rows - 1 && currentCol == cols - 1) {
                return currentTime;
            }
            
            if (visited[currentRow][currentCol]) {
                continue;
            }
            visited[currentRow][currentCol] = true;
            
            for (auto& direction : movementDirections) {
                int nextRow = currentRow + direction[0];
                int nextCol = currentCol + direction[1];

                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || visited[nextRow][nextCol]) {
                    continue;
                }
                
                if (grid[nextRow][nextCol] <= currentTime + 1) {
                    priorityQueue.push({currentTime + 1, {nextRow, nextCol}});
                } else if ((grid[nextRow][nextCol] - currentTime) % 2 == 0) {
                    priorityQueue.push({grid[nextRow][nextCol] + 1, {nextRow, nextCol}});
                } else {
                    priorityQueue.push({grid[nextRow][nextCol], {nextRow, nextCol}});
                }
            }
        }
        return -1;
    }
};



//Time Complexity -> O(m*n log(m*n))
//Space Complexity -> O(m*n)
