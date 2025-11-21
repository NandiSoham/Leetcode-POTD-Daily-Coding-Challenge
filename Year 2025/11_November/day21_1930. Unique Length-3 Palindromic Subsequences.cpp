// Problem link -> https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int cnt = 0;

        vector<pair<int, int>> charIdx(26, {-1, -1});
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            int currIdx = currChar - 'a';

            if (charIdx[currIdx].first == -1) {
                charIdx[currIdx].first = i;
            }

            charIdx[currIdx].second = i;
        }

        for (int i = 0; i < 26; i++) {
            int firstIdx = charIdx[i].first;
            int lastIdx = charIdx[i].second;

            unordered_set<char> midChars;
            for (int midIdx = firstIdx + 1; midIdx <= lastIdx - 1; midIdx++) {
                midChars.insert(s[midIdx]);
            }

            cnt += midChars.size();
        }

        return cnt;
    }
};


// Time Complexity -> O(n × 26) = O(n)
// Space Complexity -> O(26) = O(1)
