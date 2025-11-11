// Problem link -> https://leetcode.com/problems/ones-and-zeroes/description/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int maxZeros, int maxOnes) {
        vector<vector<int>> dp(maxZeros + 1, vector<int>(maxOnes + 1, 0));

        for (const string& s : strs) {
            int zeros = 0, ones = 0;

            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            for (int z = maxZeros; z >= zeros; z--) {
                for (int o = maxOnes; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o], dp[z - zeros][o - ones] + 1);
                }
            }
        }

        return dp[maxZeros][maxOnes];
    }
};


//Time Complexity ->	O(n × m × k × L)
// Space Complexity ->	O(m × k)
