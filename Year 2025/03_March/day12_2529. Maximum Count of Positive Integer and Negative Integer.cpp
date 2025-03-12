// Problem Link -> https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0, negCount = 0;

        for (int num : nums) {
            posCount += num > 0;
            negCount += num < 0;
        }

        return max(posCount, negCount);
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)

// =========================================================================================
