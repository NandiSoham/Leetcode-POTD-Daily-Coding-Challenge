// Problem link -> https://leetcode.com/problems/count-number-of-balanced-permutations/description/

class Solution {
public:
    int n;
    int totalSumOfDigits;
    int MOD = 1e9 + 7;
    long long totalPossiblePermutations = 0;

    int binaryExponentiation(long long base, long long exponent) {
        if (exponent == 0) {
            return 1;
        }

        long long halfPower = binaryExponentiation(base, exponent / 2);
        long long result = (halfPower * halfPower) % MOD;
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int countValidPermutations(int digitIndex, int evenPosCountSoFar,
                               int sumSoFar, vector<int>& digitFrequency,
                               vector<long long>& inverseFactorial,
                               vector<vector<vector<int>>>& memo) {
        if (digitIndex == 10) {
            if (sumSoFar == totalSumOfDigits / 2 &&
                evenPosCountSoFar == (n + 1) / 2) {
                return totalPossiblePermutations;
            }
            return 0;
        }

        if (memo[digitIndex][evenPosCountSoFar][sumSoFar] != -1) {
            return memo[digitIndex][evenPosCountSoFar][sumSoFar];
        }

        long long totalWays = 0;

        for (int evenPlacementCount = 0;
             evenPlacementCount <= min(digitFrequency[digitIndex],
                                       (n + 1) / 2 - evenPosCountSoFar);
             evenPlacementCount++) {
            int oddPlacementCount =
                digitFrequency[digitIndex] - evenPlacementCount;

            long long denominator = (inverseFactorial[evenPlacementCount] *
                                     inverseFactorial[oddPlacementCount]) %
                                    MOD;

            long long recursiveResult = countValidPermutations(
                digitIndex + 1, evenPosCountSoFar + evenPlacementCount,
                sumSoFar + digitIndex * evenPlacementCount, digitFrequency,
                inverseFactorial, memo);

            totalWays =
                (totalWays + (recursiveResult * denominator) % MOD) % MOD;
        }

        return memo[digitIndex][evenPosCountSoFar][sumSoFar] = totalWays;
    }

    int countBalancedPermutations(string num) {
        n = num.length();
        totalSumOfDigits = 0;

        vector<int> digitFrequency(10, 0);
        for (char digitChar : num) {
            int digit = digitChar - '0';
            totalSumOfDigits += digit;
            digitFrequency[digit]++;
        }

        if (totalSumOfDigits % 2 != 0) {
            return 0;
        }

        vector<long long> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        vector<long long> inverseFactorial(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            inverseFactorial[i] =
                binaryExponentiation(factorial[i], MOD - 2) % MOD;
        }

        totalPossiblePermutations =
            (1LL * factorial[(n + 1) / 2] * factorial[n / 2]) %
            MOD;

        vector<vector<vector<int>>> memo(
            10, vector<vector<int>>((n + 1) / 2 + 1,
                                    vector<int>(totalSumOfDigits + 1, -1)));
        return countValidPermutations(0, 0, 0, digitFrequency, inverseFactorial,
                                      memo);
    }
};



