// Problem Link -> https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    int dp[201][20001];

    bool isPossibleSubset(vector<int>& nums, int target, int i){
        if(target == 0) return true;
        if(i >= nums.size()) return false;

        if(dp[i][target] != -1) {
            return dp[i][target];
        }

        bool include = false;
        if(target >= nums[i]){
            include = isPossibleSubset(nums, target - nums[i], i + 1);
        }

        bool exclude = isPossibleSubset(nums, target, i + 1);

        return dp[i][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % 2 != 0) return false;
        
        memset(dp, -1, sizeof(dp));
        int target = sum / 2;

        return isPossibleSubset(nums, target, 0);
    }
};


// Time Complexity -> O(n * target)
// Space Complexity -> O(n * target)
