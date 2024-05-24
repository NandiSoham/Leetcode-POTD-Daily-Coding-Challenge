// Problem Link -> https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

class Solution {
public:
    int maxScore, n;
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        maxScore = 0;
        n = words.size();
        vector<int> freq(26, 0);

        for (char ch : letters) {
            freq[ch - 'a']++;
        }

        solve(0, score, words, 0, freq);
        return maxScore;
    }

    void solve(int idx, vector<int>& score, vector<string>& words,
               int currScore, vector<int>& freq) {
        maxScore = max(maxScore, currScore);
        if (idx >= n)
            return;

        vector<int> tempFreq = freq;
        int tempScore = 0;
        int j = 0;

        while (j < words[idx].length()) {
            char ch = words[idx][j];
            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];

            if (tempFreq[ch - 'a'] < 0)
                break;
            j++;
        }

        if (j == words[idx].length()) {
            solve(idx + 1, score, words, currScore + tempScore, tempFreq);
        }

        solve(idx + 1, score, words, currScore, freq);
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)
