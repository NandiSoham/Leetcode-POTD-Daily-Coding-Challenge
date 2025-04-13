// Problem Link -> https://leetcode.com/problems/count-good-numbers/description/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int findPower(long long base, long long exponent) {
        if (exponent == 0) {
            return 1;
        }

        long long halfPower = findPower(base, exponent / 2);
        long long count = (halfPower * halfPower) % MOD;

        if (exponent % 2 == 1) {
            count = (count * base) % MOD;
        }

        return count;
    }

    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n + 1) / 2) * findPower(4, n / 2) % MOD;
    }
};



// Time Complexity -> O(log n)
// Space Complexity -> O(1)
