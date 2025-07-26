// Problem Link -> https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/description/

#define ALL(x) begin(x), end(x)

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long totalValid = 0;

        vector<vector<int>> blockers(n + 1);

        for (auto& pair : conflictingPairs) {
            int u = min(pair[0], pair[1]);
            int v = max(pair[0], pair[1]);
            blockers[v].push_back(u);
        }

        int recentBlock = 0, prevRecentBlock = 0;
        vector<long long> gain(n + 1, 0);

        for (int right = 1; right <= n; ++right) {
            for (int& left : blockers[right]) {
                if (left >= recentBlock) {
                    prevRecentBlock = recentBlock;
                    recentBlock = left;
                } else if (left > prevRecentBlock) {
                    prevRecentBlock = left;
                }
            }

            totalValid += right - recentBlock;
            gain[recentBlock] += recentBlock - prevRecentBlock;
        }

        return totalValid + *max_element(ALL(gain));
    }
};


// Time Complexity -> O(n + k)    n iterations + k conflicting pairs processing
// Space Complexity -> O(n)
