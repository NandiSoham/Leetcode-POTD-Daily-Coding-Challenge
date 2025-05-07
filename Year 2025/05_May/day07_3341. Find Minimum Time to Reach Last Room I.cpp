// Problem Link -> https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> CellInfo;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();

        vector<vector<int>> minArrivalTime(rows, vector<int>(cols, INT_MAX));
        priority_queue<CellInfo, vector<CellInfo>, greater<CellInfo>> minHeap;

        minArrivalTime[0][0] = 0;
        minHeap.push({0, {0, 0}});

        while (!minHeap.empty()) {
            int currentTime = minHeap.top().first;
            auto position = minHeap.top().second;
            int row = position.first;
            int col = position.second;

            minHeap.pop();
            if (row == rows - 1 && col == cols - 1) {
                return currentTime;
            }

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols) {
                    int waitTime =
                        max(moveTime[newRow][newCol] - currentTime, 0);
                    int arrivalTime = currentTime + waitTime + 1;

                    if (minArrivalTime[newRow][newCol] > arrivalTime) {
                        minArrivalTime[newRow][newCol] = arrivalTime;
                        minHeap.push({arrivalTime, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};

