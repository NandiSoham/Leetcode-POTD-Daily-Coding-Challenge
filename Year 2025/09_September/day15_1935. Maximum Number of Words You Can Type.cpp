// Problem Link -> https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int freqArr[26] = {};   
        
        for (char letter : brokenLetters) {
            freqArr[letter - 'a']++;
        }

        int validWords = 0;
        bool isBroken = false;

        for (int i = 0; i < n; i++) {
            if (text[i] != ' ' && freqArr[text[i] - 'a'] > 0) {
                isBroken = true;   
            }

            if (text[i] == ' ') { 
                if (!isBroken) validWords++;
                isBroken = false;
            }
        }

        if (!isBroken) validWords++;

        return validWords;
    }
};


// Time Complexity -> O(m + n) m = brokenLetters size; n = text size
// Space Complexity -> O(26) ~ O(1)
