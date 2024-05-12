// Problem Link -> https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

class Solution {
public:

    int findMaxLocal(vector<vector<int>>& grid, int row, int col){
        int maxElement = 0;

        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));
        
        for(int row = 0; row < n-2; row++){
            for(int col = 0; col < n-2; col++){
                maxLocal[row][col] = findMaxLocal(grid, row, col);
            }
        }
        return maxLocal;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O((n-2)^2)
