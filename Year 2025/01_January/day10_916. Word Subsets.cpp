// Problem Link -> https://leetcode.com/problems/word-subsets/description/

class Solution {
public:
    bool isSubset(vector<int>& freqWord2, vector<int>& freqWord1) {
        for (int i = 0; i < 26; i++) {
            if (freqWord1[i] < freqWord2[i]) return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> universalWords;

        vector<int> freqWord2(26);
        for (string& word : words2) {
            vector<int> currFreq(26, 0);

            for (char& ch : word) {
                currFreq[ch - 'a']++;
                freqWord2[ch - 'a'] = max(currFreq[ch - 'a'], freqWord2[ch - 'a']);
            }
        }

        for (string& word : words1) {
            vector<int> freqWord1(26, 0);

            for (char& ch : word) {
                freqWord1[ch - 'a']++;
            }

            if (isSubset(freqWord2, freqWord1)) {
                universalWords.push_back(word);
            }
        }

        return universalWords;
    }
};



// Time Complexity : O(n*l1 + m*l2) , n = # of words in words1, l1 = average length of word in words1, similarly m and l2 for words2
// Space Complexity : O(26) ~= O(1)
