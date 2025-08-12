// Problem Link -> https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

class Solution {
public:
    int mod = 1e9 + 7;
    int memo[301][301];

    int countWays(int n, int base, int power){
        if(n == 0) return 1;
        if(n < 0) return 0;

        int currVal = pow(base, power);
        if(currVal > n) return 0;

        if(memo[n][base] != -1){
            return memo[n][base];
        }

        int take = countWays(n - currVal, base + 1, power);
        int notTake = countWays(n, base + 1, power);

        return memo[n][base] = (take + notTake) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(memo, -1, sizeof(memo));
        return countWays(n, 1, x);
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(n^2)
