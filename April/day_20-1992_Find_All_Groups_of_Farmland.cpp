class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;

        int m = land.size();
        int n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int row = i, col = j;

                    while (row < m && land[row][j] == 1) {
                        while (col < n && land[row][col] == 1) {
                            col++;
                        }
                        row++;
                    }
                    row--;   

                    for (int r = i; r <= row; r++) {
                        for (int c = j; c < col; c++) {
                            land[r][c] = -1;
                        }
                    }

                    result.push_back({i, j, row, col - 1});
                }
            }
        }
        return result;
    }
};



// Time Complexity -> O(m X n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/find-all-groups-of-farmland/description/
