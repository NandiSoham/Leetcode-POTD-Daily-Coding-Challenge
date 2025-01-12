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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.length();

        if (length % 2 != 0) return false;

        int unmatchedOpen = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(' || locked[i] == '0') unmatchedOpen++;
            else unmatchedOpen--;

            if (unmatchedOpen < 0) return false;
        }

        int unmatchedClose = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') unmatchedClose++;
            else unmatchedClose--;

            if (unmatchedClose < 0) return false;
        }

        return true;
    }
};



// Time Complexity: O (n)
// Space Complexity: O (1)

// =========================================================================================
