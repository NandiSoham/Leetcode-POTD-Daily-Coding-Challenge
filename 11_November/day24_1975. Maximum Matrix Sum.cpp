// Problem Link -> https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        long long totalSum = 0;
        int negativeCount = 0; 
        int smallestAbsoluteValue = INT_MAX;

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int currentElement = matrix[row][col];
                totalSum += abs(currentElement);

                if (currentElement < 0) {
                    negativeCount++;
                }

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(currentElement));
            }
        }

        if (negativeCount % 2 == 0) {
            return totalSum;
        }

        return totalSum - 2 * smallestAbsoluteValue;
    }
};



// Time Complexity -> O(row * col)
// Space Complexity -> O(1)
