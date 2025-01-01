// Problem Link -> https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        vector<vector<int>> segmentCount(26, vector<int>(n + 1, 0));

        char previousChar = s[0];
        int currentLength = 0;

        for (int i = 0; i < n; i++) {
            char currentChar = s[i];
            if (currentChar == previousChar) {
                currentLength++;
            } else {
                currentLength = 1;
                previousChar = currentChar;
            }
            segmentCount[currentChar - 'a'][currentLength]++;
        }

        int maxLength = 0;

        for (int i = 0; i < 26; i++) {
            int cumulativeSum = 0;
            for (int length = n; length >= 1; length--) {
                cumulativeSum += segmentCount[i][length];
                if (cumulativeSum >= 3) {
                    maxLength = max(maxLength, length);
                    break;
                }
            }
        }

        return maxLength == 0 ? -1 : maxLength;
    }
};
