// Problem Link -> https://leetcode.com/problems/count-servers-that-communicate/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    if (canCommunicate) {
                        resultServers++;
                    } else {

                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
};



// Time Complexity: O((m*n) * (m+n))
// Space Complexity: O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);
    
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) { 
                    indexColCount[col] += 1;
                    indexRowCount[row] += 1;
                }
            }
        }

        int resultServers = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
};



// Time Complexity: O (m * n)
// Space Complexity: O (m + n)

// =========================================================================================
