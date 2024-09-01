// Problem Link -> https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

// --------------------------------- Approach - 1 --------------------------------

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ansMatrix(m, vector<int>(n));
        int indexIndecator = 0;

        if(m * n != original.size()) return{};

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                ansMatrix[row][col] = original[indexIndecator];
                indexIndecator++;
            }
        }

        return ansMatrix;
    }
};


// Time Comeplexity -> O(m * n)
// Space Complexity -> O(1)

// ----------------------------------------------------------------------------------
