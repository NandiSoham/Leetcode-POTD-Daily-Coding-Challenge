// Problem Link -> https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

// ---------------------------------- Approach - 1 ------------------------------------

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        if(n < 4) return 0;
        sort(nums.begin(), nums.end());

        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-3] - nums[1]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-1] - nums[3]);

        return ans;

    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

// ------------------------------------------------------------------------------------
