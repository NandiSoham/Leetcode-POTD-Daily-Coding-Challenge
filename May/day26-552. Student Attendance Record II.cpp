// Problem Link -> https://leetcode.com/problems/student-attendance-record-ii/description/

class Solution {
public:
    int modNum = 1e9 + 7;
    int memo[100001][2][3];

    int checkRecord(int n) {
        memset(memo, -1, sizeof(memo));
        return solve(n, 0, 0);
    }

    int solve(int n, int absentCount, int conLateCount) {
        if (absentCount > 1 || conLateCount > 2)
            return 0;

        if (n == 0)
            return 1;

        if (memo[n][absentCount][conLateCount] != -1) {
            return memo[n][absentCount][conLateCount];
        }

        int absentCase = solve(n - 1, absentCount + 1, 0) % modNum;
        int lateCase = solve(n - 1, absentCount, conLateCount + 1) % modNum;
        int presentCase = solve(n - 1, absentCount, 0) % modNum;

        return memo[n][absentCount][conLateCount] =
                   ((absentCase + lateCase) % modNum + presentCase) % modNum;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
