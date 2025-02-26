// Problem Link -> https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSubArrSum = nums[0];
        int maxSubArrSum = nums[0];

        for(int i = 1; i < n; i++){
            currSubArrSum = max (nums[i], currSubArrSum + nums[i]);
            maxSubArrSum = max (maxSubArrSum, currSubArrSum);
        }

        currSubArrSum = nums[0];
        int minSubArrSum = nums[0];

        for(int i = 1; i < n; i++){
            currSubArrSum = min (nums[i], currSubArrSum + nums[i]);
            minSubArrSum = min (minSubArrSum, currSubArrSum);
        }

        return max(maxSubArrSum, abs(minSubArrSum));
    }
};


// Time Complexity ->O(n)
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        
        int currMaxSum = nums[0];
        int currMinSum = nums[0];

        int maxSubArrSum = nums[0];
        int minSubArrSum = nums[0];

        for(int i = 1; i < n; i++){
            currMaxSum = max (nums[i], currMaxSum + nums[i]);
            maxSubArrSum = max (maxSubArrSum, currMaxSum);

            currMinSum = min (nums[i], currMinSum + nums[i]);
            minSubArrSum = min (minSubArrSum, currMinSum);
        }

        return max(maxSubArrSum, abs(minSubArrSum));
    }
};


// Time Complexity ->O(n)
// Space Complexity -> O(1)

// =========================================================================================
