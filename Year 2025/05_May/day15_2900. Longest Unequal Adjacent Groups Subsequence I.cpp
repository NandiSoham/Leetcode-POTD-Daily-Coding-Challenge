// Problem link -> https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> ans;
        for(int i = 0; i < n; i++) {
            if(i == 0 || groups[i] != groups[i-1]) { 
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};


// Time COmplexity -> O(n)
// Space COmeplexity -> O(1)
