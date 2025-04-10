// Problem Link -> https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

class Solution {
public:
    long long solve(string& numberStr, string& suffix, int maxDigit) {
        if (numberStr.length() < suffix.length()) {
            return 0;
        }

        long long totalCount = 0;
        string endingSegment =
            numberStr.substr(numberStr.length() - suffix.length());
        int prefixLength = numberStr.length() - suffix.length();

        for (int idx = 0; idx < prefixLength; idx++) {
            int currentDigit = numberStr[idx] - '0';

            if (currentDigit <= maxDigit) {
                totalCount +=
                    currentDigit * pow(maxDigit + 1, prefixLength - idx - 1);
            } else {
                totalCount += pow(maxDigit + 1, prefixLength - idx);
                return totalCount;
            }
        }

        if (endingSegment >= suffix) {
            totalCount += 1;
        }

        return totalCount;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startString = to_string(start - 1);
        string finishString = to_string(finish);

        return solve(finishString, s, limit) - solve(startString, s, limit);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
