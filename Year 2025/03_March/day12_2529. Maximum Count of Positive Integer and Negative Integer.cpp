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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaIsPositive = [](int num) {
            return num > 0;
        };

        auto lambdaIsNegative = [](int num) {
            return num < 0;
        };

        int positiveCount = count_if(nums.begin(), nums.end(), lambdaIsPositive);
        int negativeCount = count_if(nums.begin(), nums.end(), lambdaIsNegative);

        return max(positiveCount, negativeCount);
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstPosIdx = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int firstNegIdx = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        return max(n - firstPosIdx, firstNegIdx);
    }
};


// Time Complexity -> O(log(n))
// SPace Complexity -> O(1)

// =========================================================================================
