// Problem Link -> https://leetcode.com/problems/trapping-rain-water-ii/description/

class Solution {
public:
    typedef pair<int, pair<int, int>> CellInfo;  
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        priority_queue<CellInfo, vector<CellInfo>, greater<>> minHeap;
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; ++row) {
            for (int col : {0, cols - 1}) {  
                minHeap.push({heightMap[row][col], {row, col}});
                isVisited[row][col] = true;
            }
        }

        for (int col = 0; col < cols; ++col) {
            for (int row : {0, rows - 1}) {  
                minHeap.push({heightMap[row][col], {row, col}});
                isVisited[row][col] = true;
            }
        }

        int totalWater = 0;
        
        while (!minHeap.empty()) {
            auto [currentHeight, cell] = minHeap.top();
            minHeap.pop();

            int row = cell.first;
            int col = cell.second;

            for (vector<int>& direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                if (newRow >= 0 && newRow < rows && 
                    newCol >= 0 && newCol < cols && 
                    !isVisited[newRow][newCol]) {
                    
                    totalWater += max(0, currentHeight - heightMap[newRow][newCol]);
                    
                    minHeap.push({max(currentHeight, heightMap[newRow][newCol]), {newRow, newCol}});  
                    isVisited[newRow][newCol] = true;
                }
            }
        }

        return totalWater;
    }
};



// Time Complexity -> O(R*C log(R*C))
// Space Complexity -> O(R*C)
