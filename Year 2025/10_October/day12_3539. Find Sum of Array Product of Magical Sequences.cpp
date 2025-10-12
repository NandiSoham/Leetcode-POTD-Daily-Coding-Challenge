// Problem link -> https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int n, targetBits;

    map<tuple<ll, int, int, int>, ll> dpCache;
    vector<ll> fact, invFact;

    ll modPow(ll base, ll exp) {
        if (exp == 0) return 1;

        ll half = modPow(base, exp / 2);
        ll res = (half * half) % MOD;
        if (exp % 2) res = (res * base) % MOD;

        return res;
    }

    ll comb(int n, int r) {
        if (r > n)return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    ll dfs(ll bitSum, int remaining, int bitsNeeded, int idx,
           vector<int>& nums) {
        auto key = make_tuple(bitSum, remaining, bitsNeeded, idx);
        if (dpCache.count(key))
            return dpCache[key];

        if (remaining == 0 && __builtin_popcountll(bitSum) == bitsNeeded)
            return 1;
        if (remaining == 0 || idx >= n)
            return 0;

        ll total = 0;

        total = (total + dfs((bitSum >> 1), remaining,
                             bitsNeeded - (bitSum & 1), idx + 1, nums)) % MOD;

        for (int count = 1; count <= remaining; ++count) {
            ll updatedSum = bitSum + count;
            ll nextVal = dfs((updatedSum >> 1), remaining - count,
                             bitsNeeded - (updatedSum & 1), idx + 1, nums);

            nextVal = (modPow(nums[idx], count) * nextVal) % MOD;
            nextVal = (nextVal * comb(remaining, count)) % MOD;

            total = (total + nextVal) % MOD;
        }

        return dpCache[key] = total;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        targetBits = k;
        n = nums.size();

        fact.assign(m + 1, 1);
        invFact.assign(m + 1, 1);

        for (int i = 2; i <= m; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;

        for (int i = 0; i <= m; ++i)
            invFact[i] = modPow(fact[i], MOD - 2);

        return (int)(dfs(0, m, k, 0, nums) % MOD);
    }
};


