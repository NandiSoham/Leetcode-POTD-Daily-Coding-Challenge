// Problem Link -> https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int xorCount = 0;
        int minLoss = INT_MAX;

        for (long long val : nums) {
            int xorVal = val ^ k;

            if (xorVal > val) {
                xorCount++;
                totalSum += xorVal;
            } else {
                totalSum += val;
            }

            minLoss = min((long long)minLoss, abs(val - xorVal));
        }

        if (xorCount % 2 == 0)
            return totalSum;

        return totalSum - minLoss;
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(1)
