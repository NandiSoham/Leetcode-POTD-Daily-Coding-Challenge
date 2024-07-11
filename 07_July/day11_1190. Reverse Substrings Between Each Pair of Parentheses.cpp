// Problem Link -> https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

// ---------------------------------- Approach - 1 --------------------------------

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> skipLength;
        string ans = "";

        for (char& ch : s) {
            if (ch == '(') {
                skipLength.push(ans.length());
            } else if (ch == ')') {
                int len = skipLength.top();
                skipLength.pop();
                reverse(ans.begin() + len, ans.end());
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(n)
// --------------------------------------------------------------------------------
