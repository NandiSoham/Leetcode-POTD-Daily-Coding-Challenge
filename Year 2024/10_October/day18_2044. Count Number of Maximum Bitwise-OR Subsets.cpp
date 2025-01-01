// Problem Link -> https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

class Solution {
public:
    int countSubsets(int index, int currentOr, vector<int>& nums, int maxOrValue) {
        if (index == nums.size()) {
            return currentOr == maxOrValue ? 1 : 0;
        }

        int includeCurrent = countSubsets(index + 1, currentOr | nums[index], nums, maxOrValue);
        int excludeCurrent = countSubsets(index + 1, currentOr, nums, maxOrValue);

        return includeCurrent + excludeCurrent;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;

        for (int &num : nums) {
            maxOrValue |= num;
        }

        int initialOr = 0;
        return countSubsets(0, initialOr, nums, maxOrValue);
    }
};



// Time Complexity -> O(2^n)
// Space Complexity ->O(1)
