// Problem Link -> https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string result = "";
        int i = len1, j = len2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    result.push_back(str1[i - 1]);
                    i--;
                } else {
                    result.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0) {
            result.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(str2[j - 1]);
            j--;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};


// Time Complexity -> O(m*n)
// Space Complexity -> O(m*n)
