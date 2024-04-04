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

// ------------------------------ APPROACH - 2 ( Without using extra space) -------------------------------

class Solution {
public:
    int maxDepth(string s) {
        int openParentheses = 0;
        int resultDepth = 0;

        for(char &ch:s){
            if(ch == '(') openParentheses++;
            else if(ch == ')') openParentheses--;

            resultDepth = max(resultDepth, openParentheses);
        }

        return resultDepth;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// --------------------------------------------------------------------------------------------------------
