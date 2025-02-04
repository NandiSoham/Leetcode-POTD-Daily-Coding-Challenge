// Problem Link -> https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curSum = nums[i];

            for (int j = i + 1; j < n; j++) {
                
                if (nums[j] > nums[j - 1]) {
                    curSum += nums[j];
                    cout << curSum;
                } else
                    break;
            }

            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// =========================================================================================
