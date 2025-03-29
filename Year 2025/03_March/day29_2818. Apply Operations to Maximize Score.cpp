// Problem link -> https://leetcode.com/problems/apply-operations-to-maximize-score/description/

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long powerMod(long long base, long long exponent) {
        if (exponent == 0)
            return 1;
        long long halfPower = powerMod(base, exponent / 2);
        long long result = (halfPower * halfPower) % MOD;
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }

    vector<int> sievePrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primeList;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primeList.push_back(i);
            }
        }

        return primeList;
    }

    vector<int> computePrimeFactorsCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> factorCounts(n, 0);

        int maxValue = *max_element(begin(nums), end(nums));
        vector<int> primes = sievePrimes(maxValue);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num) {
                    break;
                }

                if (num % prime != 0) {
                    continue;
                }

                factorCounts[i]++;
                while (num % prime == 0) {
                    num /= prime;
                }
            }
            if (num > 1) {
                factorCounts[i]++;
            }
        }

        return factorCounts;
    }

    vector<int> nextGreaterElementIndex(vector<int>& factorCounts) {
        int n = factorCounts.size();
        vector<int> nextIndex(n, n);
        stack<int> indexStack;

        for (int i = n - 1; i >= 0; i--) {
            while (!indexStack.empty() &&
                   factorCounts[indexStack.top()] <= factorCounts[i]) {
                indexStack.pop();
            }

            nextIndex[i] = indexStack.empty() ? n : indexStack.top();
            indexStack.push(i);
        }

        return nextIndex;
    }

    vector<int> prevGreaterElementIndex(vector<int>& factorCounts) {
        int n = factorCounts.size();
        vector<int> prevIndex(n, -1);
        stack<int> indexStack;

        for (int i = 0; i < n; i++) {
            while (!indexStack.empty() &&
                   factorCounts[indexStack.top()] < factorCounts[i]) {
                indexStack.pop();
            }

            prevIndex[i] = indexStack.empty() ? -1 : indexStack.top();
            indexStack.push(i);
        }

        return prevIndex;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> factorCounts = computePrimeFactorsCount(nums);
        vector<int> nextIndex = nextGreaterElementIndex(factorCounts);
        vector<int> prevIndex = prevGreaterElementIndex(factorCounts);

        int n = nums.size();
        vector<long long> subarrayContribution(n, 0);

        for (int i = 0; i < n; i++) {
            subarrayContribution[i] =
                (long long)(nextIndex[i] - i) * (i - prevIndex[i]);
        }

        vector<pair<int, int>> sortedElements(n);
        for (int i = 0; i < n; i++) {
            sortedElements[i] = {nums[i], i};
        }

        sort(begin(sortedElements), end(sortedElements), greater<>());

        long long score = 1;
        int idx = 0;

        while (k > 0) {
            auto [num, i] = sortedElements[idx];

            long long operations = min((long long)k, subarrayContribution[i]);

            score = (score * powerMod(num, operations)) % MOD;

            k -= operations;
            idx++;
        }

        return score;
    }
};
