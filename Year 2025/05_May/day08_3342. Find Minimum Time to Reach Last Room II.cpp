// Problem Link -> https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> CellData;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();

        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        priority_queue<CellData, vector<CellData>, greater<CellData>> minHeap;

        minTime[0][0] = 0;
        minHeap.push({0, {0, 0}});

        while (!minHeap.empty()) {
            int currTime = minHeap.top().first;
            auto pos = minHeap.top().second;
            int row = pos.first;
            int col = pos.second;

            minHeap.pop();
            if (row == rows - 1 && col == cols - 1) {
                return currTime;
            }

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols) {
                    int movementCost = (newRow + newCol) % 2 == 0 ? 2 : 1;
                    int waitTime = max(moveTime[newRow][newCol] - currTime, 0);
                    int newTime = currTime + waitTime + movementCost;

                    if (minTime[newRow][newCol] > newTime) {
                        minTime[newRow][newCol] = newTime;
                        minHeap.push({newTime, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};


// Time Complexity -> O(R∗CLog(R∗C))
// Space Complexity -> O(R*C)
