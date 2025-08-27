// Problem Link -> https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/

class Solution {
public:
    int m, n;
    const vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dp[501][501][4][2];

    int traverseDiagonal(int i, int j, int d, bool canTurn, int nextVal, vector<vector<int>>& grid) {
        int new_i = i + dir[d][0];
        int new_j = j + dir[d][1];

        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n ||
            grid[new_i][new_j] != nextVal) {
            return 0;
        }

         if (dp[new_i][new_j][d][canTurn] != -1)
            return dp[new_i][new_j][d][canTurn];

        // Option 1: keep moving in same direction
        int keepMoving = 1 + traverseDiagonal(new_i, new_j, d, canTurn, nextVal == 2 ? 0 : 2, grid);

        // Option 2: clockwise 90-degree turn
        int turnPath = 0;
        if (canTurn) {
            int newDir = (d + 1) % 4;
            turnPath = 1 + traverseDiagonal(new_i, new_j, newDir, false, nextVal == 2 ? 0 : 2, grid);
        }

        int bestPath;
        if (canTurn) {
            bestPath = max(keepMoving, turnPath);
        } else
            bestPath = keepMoving;

        dp[new_i][new_j][d][canTurn] = bestPath;
        return bestPath;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int len = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        len = max(len, 1 + traverseDiagonal(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        return len;
    }
};


// Time Complexity -> O(m * n)
// Space complexity -> O(m * n)
