// Problem Link -> https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        unordered_map<string, int> patternFrequency;

        for (auto& row : matrix) {
            string rowPattern = "";

            int firstValue = row[0];
            for (int col = 0; col < numCols; col++) {
                rowPattern += (row[col] == firstValue) ? "S" : "B";
            }

            patternFrequency[rowPattern]++;
        }

        int maxEqualRows = 0;
        for (auto& pattern : patternFrequency) {
            maxEqualRows = max(maxEqualRows, pattern.second);
        }

        return maxEqualRows;
    }
};



// Time Complexity -> O(row * col)
// Space Complexity -> O(row * col)
