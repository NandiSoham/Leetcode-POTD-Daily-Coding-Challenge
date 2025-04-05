// Problem Link -> https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

// ----------------------------------------- Approach - 1 -----------------------------------------

class Solution {
public:
    int solve(vector<int>& nums, int i, int xorVal) {

        if (i == nums.size()) {
            return xorVal;
        }

        int inc = solve(nums, i + 1, nums[i] ^ xorVal);
        int exc = solve(nums, i + 1, xorVal);

        return inc + exc;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)

//-------------------------------------------------------------------------------------------------
