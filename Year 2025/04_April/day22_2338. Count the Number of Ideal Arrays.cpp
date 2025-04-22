// Problem link -> https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/

class Solution {
public:
#define ll long long

    ll dpCount[15][10005];
    ll dpPrefixSum[15][10005];
    ll sequenceOptions[15];
    int MOD = 1e9 + 7;

    void countUniqueSequences(int currentValue, int depth, int& maxValue) {
        sequenceOptions[depth] += 1;
        for (int multiplier = 2; currentValue * multiplier <= maxValue;
             ++multiplier)
            countUniqueSequences(currentValue * multiplier, depth + 1,
                                 maxValue);
    }

    int idealArrays(int n, int maxValue) {
        memset(dpCount, 0, sizeof(dpCount));
        memset(dpPrefixSum, 0, sizeof(dpPrefixSum));
        memset(sequenceOptions, 0, sizeof(sequenceOptions));

        for (int value = 1; value <= 10000; ++value) {
            dpCount[1][value] = 1;
            dpPrefixSum[1][value] = value;
        }

        for (int length = 2; length <= 14; ++length) {
            for (int value = length; value <= 10000; ++value) {
                dpCount[length][value] = dpPrefixSum[length - 1][value - 1];
                dpPrefixSum[length][value] =
                    dpCount[length][value] + dpPrefixSum[length][value - 1];
                dpCount[length][value] %= MOD;
                dpPrefixSum[length][value] %= MOD;
            }
        }

        for (int value = 1; value <= maxValue; ++value)
            countUniqueSequences(value, 1, maxValue);

        ll totalWays = 0;
        ll combinationWays;
        for (int length = 1; length <= 14; ++length) {
            combinationWays = dpCount[length][n] * sequenceOptions[length];
            combinationWays %= MOD;
            totalWays += combinationWays;
            totalWays %= MOD;
        }
        return totalWays;
    }
};
