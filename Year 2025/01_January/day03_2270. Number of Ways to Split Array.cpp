// Problem Link -> https://leetcode.com/problems/number-of-ways-to-split-array/description/

// ===================================== Approach - 1 ===================================

class Solution {
public:
    typedef long long ll;

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int splitCount = 0;
        vector<ll> cumulativeSum(n);
        cumulativeSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            cumulativeSum[i] = cumulativeSum[i - 1] + nums[i];
        }

        for(int i = 0; i < n - 1; i++){
            
            ll leftSum = cumulativeSum[i];
            ll rightSum = cumulativeSum[n - 1] - cumulativeSum[i];

            if(leftSum >= rightSum) splitCount++;
        }

        return splitCount;
    }
};



// Time Complexity: O (n)
// Space Complexity: O (n)

// ======================================================================================
