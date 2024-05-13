// Problem Link -> https://leetcode.com/problems/score-after-flipping-matrix/description/

// ---------------------------------------- Approach - 1 ---------------------------------------

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // check and set the first column's value in each row
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    grid[i][j] = 1 - grid[i][j]; //flipping
                }
            }
        }

        for(int j = 1; j < n; j++){
            int zeroCount = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 0) zeroCount++;
            }

            int oneCount = m - zeroCount;
            if(zeroCount > oneCount){
                for(int i = 0; i < m; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int score = 0;
        for(int i= 0; i < m; i++){
            for(int j = 0; j <n; j++){
                int value = grid[i][j] * pow(2, n -j -1);
                score += value;
            }
        }

        return score;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------
