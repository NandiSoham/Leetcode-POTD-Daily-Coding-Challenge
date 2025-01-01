// Problem Link -> https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

class Solution {
public:
    int gridSize;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool hasSafePath(vector<vector<int>>& nearestThiefDistances,
                     int safenessFactor) {
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(gridSize, vector<bool>(gridSize, false));
        que.push({0, 0});
        visited[0][0] = true;

        if (nearestThiefDistances[0][0] < safenessFactor)
            return false;

        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();

            if (curr_i == gridSize - 1 && curr_j == gridSize - 1)
                return true;

            for (const auto& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if (new_i >= 0 && new_i < gridSize && new_j >= 0 &&
                    new_j < gridSize && !visited[new_i][new_j]) {
                    if (nearestThiefDistances[new_i][new_j] < safenessFactor)
                        continue;
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        gridSize = grid.size();

        vector<vector<int>> nearestThiefDistances(gridSize,
                                                  vector<int>(gridSize, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(gridSize, vector<bool>(gridSize, false));

        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                nearestThiefDistances[curr_i][curr_j] = level;

                for (const auto& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if (new_i < 0 || new_i >= gridSize || new_j < 0 ||
                        new_j >= gridSize || visited[new_i][new_j])
                        continue;

                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            level++;
        }

        int low = 0;
        int high = 400;
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (hasSafePath(nearestThiefDistances, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
