// Problem link -> https://leetcode.com/problems/find-the-original-typed-string-ii/description/

class Solution {
public:
    int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> segmentLengths;
        int segmentCount = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i - 1]) {
                segmentCount++;
            } else {
                segmentLengths.push_back(segmentCount);
                segmentCount = 1;
            }
        }
        segmentLengths.push_back(segmentCount);

        long long totalWays = 1;
        for(int &len : segmentLengths) {
            totalWays = (totalWays * len) % MOD;
        }

        if(segmentLengths.size() >= k) {
            return totalWays;
        }

        int segmentSize = segmentLengths.size();
        vector<vector<int>> dp(segmentSize + 1, vector<int>(k + 1, 0));

        for(int suffix = k - 1; suffix >= 0; suffix--) {
            dp[segmentSize][suffix] = 1;
        }

        for(int i = segmentSize - 1; i >= 0; i--) {
            vector<int> prefixSum(k + 1, 0);
            for(int j = 1; j <= k; j++) {
                prefixSum[j] = (prefixSum[j - 1] + dp[i + 1][j - 1]) % MOD;
            }

            for(int suffix = k - 1; suffix >= 0; suffix--) {
                int left = suffix + 1;
                int right = suffix + segmentLengths[i];

                if(right + 1 > k) {
                    right = k - 1;
                }

                if(left <= right) {
                    dp[i][suffix] = (prefixSum[right + 1] - prefixSum[left] + MOD) % MOD;
                }
            }
        }

        long long invalidWays = dp[0][0];
        return (totalWays - invalidWays + MOD) % MOD;
    }
};
