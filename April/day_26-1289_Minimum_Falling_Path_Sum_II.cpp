// Problem Link -> https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    int n;
    int dpArr[201][201];

    int solve(int col, int row, vector<vector<int>>& grid){
        if(row == n - 1) return grid[row][col];
        int ans = INT_MAX;

        if(dpArr[row][col] != -1) return dpArr[row][col];

        for(int nextCol = 0; nextCol < n; nextCol++){
            if(nextCol != col){
                ans = min(ans, solve(nextCol, row + 1, grid));
            }
        }
        return dpArr[row][col] = ans + grid[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dpArr, -1, sizeof(dpArr));
        int result = INT_MAX;

        for(int col = 0; col < n; col++){
            result = min(result, solve(col, 0, grid));
        }
        return result;
    }
};


// Time Complexity -> O(n^3)
// Space Complexity -> O(n^2)
