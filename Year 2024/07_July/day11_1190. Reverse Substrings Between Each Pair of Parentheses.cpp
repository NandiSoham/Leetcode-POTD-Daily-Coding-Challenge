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

// ---------------------------------- Approach - 2 --------------------------------

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openIdx;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                openIdx.push(i);
            } else if(s[i] == ')'){
                int j = openIdx.top();
                openIdx.pop();
                arr[i] = j;
                arr[j] = i;
            }
        }

        string ans = "";
        int flag = 1;
        for(int i = 0; i < n; i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = arr[i];
                flag = -flag;
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
// --------------------------------------------------------------------------------
