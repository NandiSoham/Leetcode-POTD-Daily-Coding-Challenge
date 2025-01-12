// Problem Link -> https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l = s.length();
        if (l % 2 != 0)
            return false;

        stack<int> openParentheses;
        stack<int> flexibleParentheses;

        for (int i = 0; i < l; i++) {
            if (locked[i] == '0')
                flexibleParentheses.push(i);
            else if (s[i] == '(')
                openParentheses.push(i);
            else if (s[i] == ')') {
                if (!openParentheses.empty())
                    openParentheses.pop();
                else if (!flexibleParentheses.empty())
                    flexibleParentheses.pop();
                else
                    return false;
            }
        }

        while (!openParentheses.empty() && !flexibleParentheses.empty() &&
               openParentheses.top() < flexibleParentheses.top()) {
            openParentheses.pop();
            flexibleParentheses.pop();
        }

        return openParentheses.empty();
    }
};




// Time Complexity: O (n)
// Space Complexity: O (n)

// =========================================================================================
