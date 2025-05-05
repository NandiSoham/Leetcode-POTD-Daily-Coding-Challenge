// Problem Link -> https://leetcode.com/problems/domino-and-tromino-tiling/description/

class Solution {
public:
    int MOD = 1000000007;
    int numTilings(int n) {
        if(n == 1 || n == 2)
            return n;
        
        vector<int> ways(n + 1, 0);
        
        ways[1] = 1;
        ways[2] = 2;
        ways[3] = 5;
        
        for(int i = 4; i <= n; i++) {
            ways[i] = (2 * ways[i - 1] % MOD + ways[i - 3] % MOD) % MOD;
        }
        
        return ways[n];
    }
};



// Time Comeplexity -> O(n)
// Space Complexity -> O(1)
