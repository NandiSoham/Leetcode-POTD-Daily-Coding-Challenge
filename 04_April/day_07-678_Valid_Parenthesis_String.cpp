// Problem Link -> https://leetcode.com/problems/valid-parenthesis-string/description/

// -------------------------- Approach - 1 ( DP ->  recursion + memoization) --------------------------

class Solution {
public:
    int memArr[101][101];

    bool solveParentheses(int idx, int openParentheses, string &s, int n) {
        bool isValid = false;

        if (idx == n) {   // base case
            return openParentheses == 0;
        }

        if (memArr[idx][openParentheses] != -1) {
            return memArr[idx][openParentheses];
        }

        if (s[idx] == '(') {
            isValid |= solveParentheses(idx + 1, openParentheses + 1, s, n);
        } else if (s[idx] == '*') {
            isValid |= solveParentheses(idx + 1, openParentheses + 1, s, n);
            isValid |= solveParentheses(idx + 1, openParentheses, s, n);
            if (openParentheses > 0)
                isValid |= solveParentheses(idx + 1, openParentheses - 1, s, n);
        } else if (s[idx] == ')') {
            if (openParentheses > 0)
                isValid |= solveParentheses(idx + 1, openParentheses - 1, s, n);
        }

        return memArr[idx][openParentheses] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.length();
        memset(memArr, -1, sizeof(memArr));
        return solveParentheses(0, 0, s, n);
    }
};



// Time Complexity -> O(n*n)
// Space Complexity -> O(n*n)

// ----------------------------------------------------------------------------------------------------
