// Problem Link -> https://leetcode.com/problems/special-array-ii/description/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> cumulativeParitySum(n, 0);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cumulativeParitySum[i] = cumulativeParitySum[i - 1] + 1;
            } else {
                cumulativeParitySum[i] = cumulativeParitySum[i - 1];
            }
        }

        vector<bool> result(m, false);
        for (int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            result[i] = (cumulativeParitySum[end] - cumulativeParitySum[start] == 0);
        }

        return result;
    }
};
