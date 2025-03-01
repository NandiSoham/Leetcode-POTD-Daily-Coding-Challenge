// Problem Link -> https://leetcode.com/problems/apply-operations-to-an-array/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        int nonZeroIndex = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] != 0) {
                nums[nonZeroIndex] = nums[index];
                nonZeroIndex++;
            }
        }

        while (nonZeroIndex < n) {
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
        }

        return nums;
    }
};


// Time Complexity ->O(n)
// Space Complexity -> O(n)

// =========================================================================================
