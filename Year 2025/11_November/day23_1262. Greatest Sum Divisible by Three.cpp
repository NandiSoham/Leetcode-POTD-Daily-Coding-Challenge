// Problem link -> https://leetcode.com/problems/greatest-sum-divisible-by-three/description/

class Solution {
public:
    int dfs(int idx, int mod, vector<int>& nums, vector<vector<int>>& memo) {
        if (idx == nums.size()) {
            return (mod == 0 ? 0 : INT_MIN);
        }

        if (memo[idx][mod] != -1) 
            return memo[idx][mod];

        int includeSum = nums[idx] + dfs(idx + 1, (mod + nums[idx]) % 3, nums, memo);

        int skipSum = dfs(idx + 1, mod, nums, memo);

        return memo[idx][mod] = max(includeSum, skipSum);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(3, -1));
        return dfs(0, 0, nums, memo);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
