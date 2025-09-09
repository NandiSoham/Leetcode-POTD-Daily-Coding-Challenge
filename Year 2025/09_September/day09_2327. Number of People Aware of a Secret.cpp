// Problem Link -> https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

#define ll long long
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll current = 0, MOD = 1e9 + 7;
        vector<ll> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            if (i - delay >= 0) {
                current = (current + dp[i - delay]) % MOD;
            }
            if (i - forget >= 0) {
                current = (current - dp[i - forget] + MOD) % MOD;
            }
            dp[i] = current;
        }

        ll active = 0;
        for (int i = n - forget; i < n; i++) {
            active = (active + dp[i]) % MOD;
        }

        return active;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
