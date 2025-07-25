// Problem Link -> https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSub = 1;
        vector<vector<int>> dp(k, vector<int>(n, 1));

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int mod = (nums[i] + nums[j]) % k;
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }

        return maxSub;
    }
};



// Time Complexity -> O(n^2)
// SPace Complexity -> O(n*k)
