// Problem Link -> https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

// ------------------------------------- APPROACH -1 ( Using Stack) ---------------------------------------

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stackParentheses;
        int resultDepth = 0;

        for(char &ch:s){
            if(ch == '(') stackParentheses.push(ch);
            else if(ch == ')') stackParentheses.pop();

            resultDepth = max(resultDepth, (int)stackParentheses.size());
        }

        return resultDepth;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// --------------------------------------------------------------------------------------------------------
