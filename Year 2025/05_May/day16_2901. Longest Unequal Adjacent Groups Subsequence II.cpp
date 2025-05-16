// Problem link -> https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

class Solution {
public:

    bool isHammingDistanceOne(string &word1, string &word2) {
        int charDiff = 0;

        for(int i = 0; i < word1.length(); i++) {
            if(word1[i] != word2[i]) {
                charDiff++;
            }

            if(charDiff > 1) {
                return false;
            }
        }

        return charDiff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> longestSeqLen(n, 1);
        vector<int> prevWordIdx(n, -1);
        int maxLen = 1;
        int endIdx = 0;

        for(int current = 0; current < n; current++) {
            for(int prev = 0; prev < current; prev++) {
                if(groups[prev] != groups[current] &&
                   words[current].length() == words[prev].length() &&
                   isHammingDistanceOne(words[current], words[prev])) {
                    
                    if(longestSeqLen[prev] + 1 > longestSeqLen[current]) {
                        longestSeqLen[current] = longestSeqLen[prev] + 1;
                        prevWordIdx[current] = prev;

                        if(maxLen < longestSeqLen[current]) {
                            maxLen = longestSeqLen[current];
                            endIdx = current;
                        }
                    }
                }
            }
        }

        vector<string> ansSequence;
        while(endIdx != -1) {
            ansSequence.push_back(words[endIdx]);
            endIdx = prevWordIdx[endIdx];
        }

        reverse(begin(ansSequence), end(ansSequence));
        return ansSequence;
    }
};


