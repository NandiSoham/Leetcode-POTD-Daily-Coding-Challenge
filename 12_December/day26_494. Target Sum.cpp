// Problem Link -> https://leetcode.com/problems/target-sum/description/


class Solution {
public:

    int solve(vector<int>& nums, int target, int idx, int currSum){
        if(idx == nums.size()){
            if(currSum == target){
                return 1;
            } else return 0;
        } 

        int addOperation = solve(nums, target, idx + 1, currSum + nums[idx]);
        int substractOperation = solve(nums, target, idx + 1, currSum - nums[idx]);

        return addOperation + substractOperation;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};



// Time Complexity -> O(n*totalSum)
// Space Complexity -> O(n*totalSum)
