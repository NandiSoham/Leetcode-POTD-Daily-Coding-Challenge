// Problem Link -> https://leetcode.com/problems/strange-printer/description/

class Solution {
public:
    int strLength;
    vector<vector<int>> memo;

    int calculateMinTurns(int left, int right, string& s) {
        if (left == right)
            return 1;
        else if (left > right)
            return 0;

        if (memo[left][right] != -1)
            return memo[left][right];

        int nextIndex = left + 1;
        while (nextIndex <= right && s[nextIndex] == s[left])
            nextIndex++;

        if (nextIndex == right + 1)
            return 1;

        int turnsWithoutMerge = 1 + calculateMinTurns(nextIndex, right, s);
        int minTurnsWithMerge = INT_MAX;

        for (int j = nextIndex; j <= right; j++) {
            if (s[left] == s[j]) {
                int currentTurns = calculateMinTurns(nextIndex, j - 1, s) + calculateMinTurns(j, right, s);
                minTurnsWithMerge = min(minTurnsWithMerge, currentTurns);
            }
        }
        return memo[left][right] = min(minTurnsWithMerge, turnsWithoutMerge);
    }

    int strangePrinter(string s) {
        strLength = s.length();
        memo.resize(strLength, vector<int>(strLength + 1, -1));
        return calculateMinTurns(0, strLength - 1, s);
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(n^2)
