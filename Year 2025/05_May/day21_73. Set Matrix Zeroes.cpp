// Problem Link -> https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        for(int row = 0; row < rowCount; row++){
            if(matrix[row][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        for(int col = 0; col < colCount; col++){
            if(matrix[0][col] == 0){
                isFirstRowZero = true;
                break;
            }
        }

        for (int row = 1; row < rowCount; row++) {
            for (int col = 1; col < colCount; col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < rowCount; row++) {
            for (int col = 1; col < colCount; col++) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if(isFirstRowZero) {
            for(int col = 0; col < colCount; col++){
                matrix[0][col] = 0;
            }
        }

        if (isFirstColZero) {
            for (int row = 0; row < rowCount; row++)
                matrix[row][0] = 0;
        }
    }
};


// Time COmplexity -> O(row * col)
// Space Complexity -> O(1)
