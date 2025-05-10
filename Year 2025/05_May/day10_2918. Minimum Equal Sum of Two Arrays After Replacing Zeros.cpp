// Problem link -> https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long totalSum1 = 0;
        long long totalSum2 = 0;

        long long zeroCount1 = 0;
        long long zeroCount2 = 0;

        for (int& value : nums1) {
            totalSum1 += value;
            if (value == 0) {
                zeroCount1 += 1;
                totalSum1 += 1;
            }
        }

        for (int& value : nums2) {
            totalSum2 += value;
            if (value == 0) {
                zeroCount2 += 1;
                totalSum2 += 1;
            }
        }

        if ((totalSum1 < totalSum2 && zeroCount1 == 0) ||
            (totalSum2 < totalSum1 && zeroCount2 == 0)) {
            return -1;
        }

        return max(totalSum1, totalSum2);
    }
};

