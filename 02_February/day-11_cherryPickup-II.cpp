class Solution {
public:
    int dp[71][71][71];
    int m, n;
    int solve(vector<vector<int>>& grid, int row, int col1, int col2){

        if(row >= m) return 0;

        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        int cherryCount = grid[row][col1];
        if(col1 != col2){
            cherryCount += grid[row][col2];
        }

        int result = 0;

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int newRow = row + 1;
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n)
                    result = max(result, solve(grid, newRow, newCol1, newCol2));
            }
        }

        return dp[row][col1][col2] = cherryCount + result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, n-1);
    }
};


// Time Complexity -> O(N*M*M) * 9  -> there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times. The value 9 will change based on problem, we can ignore it also, as it's a constant
// Space Complexity -> O(N) + O(N*M*M)
// Problem Link -> https://leetcode.com/problems/cherry-pickup-ii/description/
