// Problem Link -> https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/

int MOD = 1e9 + 7;
class Solution {
public:
    long long findPower(long long base, long long exponent) {
        long long result = 1;
        base %= MOD;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return result;
    }
    
    long long nCr(int n, int r, vector<long long>& factorial,
                  vector<long long>& inverseFactorial) {
        return factorial[n] * inverseFactorial[n - r] % MOD *
               inverseFactorial[r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n + 1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        vector<long long> inverseFactorial(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            inverseFactorial[i] = findPower(factorial[i], MOD - 2);
        }

        long long result = nCr(n - 1, k, factorial, inverseFactorial);

        result = result * m % MOD;

        result = result * findPower(m - 1, n - k - 1) % MOD;

        return result;
    }
};



// Time Complexity -> O(log(n - k - 1))
// Space Complexity -> O(n)
