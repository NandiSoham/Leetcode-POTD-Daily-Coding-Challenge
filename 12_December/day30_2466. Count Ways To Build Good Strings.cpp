// Problem Link -> https://leetcode.com/problems/count-ways-to-build-good-strings/description/

class Solution {
public:
    int result;
    int lowerBound, upperBound;
    int zeroCost, oneCost;
    const int MODULO = 1e9 + 7;

    int calculateWays(int length, vector<int>& memoization) {
        if (length > upperBound)
            return 0;

        if (memoization[length] != -1) {
            return memoization[length];
        }

        bool withinBounds = false;
        if (length >= lowerBound && length <= upperBound) {
            withinBounds = true;
        }

        int addZero = calculateWays(length + zeroCost, memoization);
        int addOne = calculateWays(length + oneCost, memoization);

        return memoization[length] = (withinBounds + addZero + addOne) % MODULO;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        result = 0;
        lowerBound = low;
        upperBound = high;
        zeroCost = zero;
        oneCost = one;

        vector<int> memoization(upperBound + 1, -1);
        return calculateWays(0, memoization);
    }
};



// Time Complexity -> O(H)
// Space Complxity -> O(H)
