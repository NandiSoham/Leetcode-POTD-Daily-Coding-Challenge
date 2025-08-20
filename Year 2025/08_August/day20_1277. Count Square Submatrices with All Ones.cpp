// Problem Link -> https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int totalSquares = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // edge cells
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                }
                totalSquares += dp[i][j];
            }
        }
        
        return totalSquares;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(m*n)
