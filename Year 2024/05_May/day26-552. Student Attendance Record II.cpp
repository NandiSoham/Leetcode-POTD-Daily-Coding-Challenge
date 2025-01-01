// Problem Link -> https://leetcode.com/problems/student-attendance-record-ii/description/

//------------------------------ Approach - 1 ( Recursion + Memoization) ---------------------------------
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

//------------------------------------------------------------------------------------------------------------

//--------------------------------------- Approach - 2 (Bottom Up)--------------------------------------------

class Solution {
public:
    int checkRecord(int n) {
        int modNum = 1e9 + 7;
        int memo[100001][2][3];

        //base case
        for(int A = 0; A <=1; A++){
            for(int L = 0;  L <= 2; L++){
                memo[0][A][L] = 1;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int A = 0; A<=1; A++){
                for(int L = 0; L <= 2; L++){
                    int ans = 0;

                    // Present case
                    ans = (ans + memo[i-1][A][0]) % modNum;

                    // Late case
                    if (L+1 <= 2) {
                        ans = (ans + memo[i-1][A][L+1]) % modNum;
                    }

                    // Absent case
                    if (A+1 <= 1) {
                        ans = (ans + memo[i-1][A+1][0]) % modNum;
                    }

                    memo[i][A][L] = ans % modNum;
                }
            }
        }

        return memo[n][0][0];
    }
};


// ----------------------------------------------------------------------------------------
