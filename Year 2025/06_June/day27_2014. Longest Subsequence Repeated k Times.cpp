// Problem Link -> https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/

class Solution {
public:
    string ansStr = "";

    bool isSubsequence(string& original, string& pattern, int repeatCount) {
        int origIdx = 0;
        int patIdx = 0;
        int patLen = pattern.length();
        int origLen = original.length();

        while (origIdx < origLen && patIdx < repeatCount * patLen) {
            if (original[origIdx] == pattern[patIdx % patLen])
                patIdx++;
            origIdx++;
        }

        return patIdx == repeatCount * patLen;
    }

    bool backtracking(string& inputStr, string& currentStr,
                      vector<bool>& usableChars, vector<int>& maxCharCount,
                      int repeatCount, int targetLen) {
        if (currentStr.length() == targetLen) {
            if (isSubsequence(inputStr, currentStr, repeatCount)) {
                ansStr = currentStr;
                return true;
            }
            return false;
        }

        for (int charIdx = 25; charIdx >= 0; charIdx--) {
            if (!usableChars[charIdx] || maxCharCount[charIdx] == 0)
                continue;

            char currentChar = charIdx + 'a';
            currentStr.push_back(currentChar);
            maxCharCount[charIdx]--;

            if (backtracking(inputStr, currentStr, usableChars, maxCharCount,
                             repeatCount, targetLen))
                return true;

            currentStr.pop_back();
            maxCharCount[charIdx]++;
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int strLen = s.length();

        int charFreq[26] = {};
        for (char& ch : s) {
            charFreq[ch - 'a']++;
        }

        vector<bool> usableChars(26, false);
        vector<int> maxCharCount(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (charFreq[i] >= k) {
                usableChars[i] = true;
                maxCharCount[i] = charFreq[i] / k;
            }
        }

        int possibleMaxLen = strLen / k;

        for (int len = possibleMaxLen; len >= 0; len--) {
            vector<int> tempCharCount = maxCharCount;
            string currentStr = "";
            if (backtracking(s, currentStr, usableChars, tempCharCount, k, len))
                return ansStr;
        }

        return ansStr;
    }
};



