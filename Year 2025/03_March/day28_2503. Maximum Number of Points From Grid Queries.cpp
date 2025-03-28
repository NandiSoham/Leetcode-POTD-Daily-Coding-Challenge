// Problem Link -> https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size();
        int cols = grid[0].size();

        int n = queries.size();
        vector<int> ans(n, 0);

        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < n; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int collectedPoints = 0;
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for(int i = 0; i < n; i++) {
            int queryVal = sortedQueries[i].first;
            int queryIdx = sortedQueries[i].second;

            while(!minHeap.empty() && minHeap.top()[0] < queryVal) {
                int currRow = minHeap.top()[1];
                int currCol = minHeap.top()[2];
                minHeap.pop();
                collectedPoints++;

                for(auto &direction : directions) {
                    int newRow = currRow + direction[0];
                    int newCol = currCol + direction[1];

                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                        minHeap.push({grid[newRow][newCol], newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            ans[queryIdx] = collectedPoints;
        }
        
        return ans;
    }
};
