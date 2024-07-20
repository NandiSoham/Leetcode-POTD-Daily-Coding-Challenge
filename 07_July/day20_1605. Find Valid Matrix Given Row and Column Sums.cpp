// Problem Link -> https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        int row = 0, col = 0;

        while(row < m && col < n){
            int minValue = min(rowSum[row], colSum[col]);
            ans[row][col] = minValue;
            rowSum[row] -= minValue;
            colSum[col] -= minValue;

            if(rowSum[row] == 0) row++;
            if(colSum[col] == 0) col++;
        }

        return ans;
    }
};



// Time Complexity -> O(m+n)
// Space Complexity -> O(1)
