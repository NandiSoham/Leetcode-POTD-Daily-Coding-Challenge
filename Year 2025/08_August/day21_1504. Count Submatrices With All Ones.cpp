// Problem Link -> https://leetcode.com/problems/count-submatrices-with-all-ones/description/

class Solution {
public:
    int countConsecutiveOnes(vector<int>& rowData) {
        int streak = 0, total = 0;
        for (int it : rowData) {
            if (it == 0) {
                streak = 0; 
            } else {
                streak++;
            }
            total += streak;
        }
        return total;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int totalCount = 0;

        for (int r1 = 0; r1 < rows; r1++) {
            vector<int> merged(cols, 1);

            for (int r2 = r1; r2 < rows; r2++) {
                for (int c = 0; c < cols; c++) {
                    merged[c] = merged[c] & mat[r2][c];
                }
                totalCount += countConsecutiveOnes(merged);
            }
        }
        return totalCount;
    }
};



// Time Complexity -> O(m^2 * n)
// Space Complexity -> O(n)
