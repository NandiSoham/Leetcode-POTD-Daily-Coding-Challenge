// Problem Link -> https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

// --------------------------------- APPROACH - 1 ( Using a Stack ) -----------------------------------

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> storeParentheses;
        unordered_set<int> removeIndex;
        string resultStr = "";

        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                storeParentheses.push(i);
            else if(s[i] == ')')
                if(storeParentheses.empty()){
                    removeIndex.insert(i);
                } else{
                    storeParentheses.pop();
                }
        }

        //In case of only open brackets "((("
        while(!storeParentheses.empty()){
            removeIndex.insert(storeParentheses.top());
            storeParentheses.pop();
        }

        // remove the characters from set
        for(int i = 0; i < n; i++){
            if(removeIndex.find(i) == removeIndex.end()){
                resultStr.push_back(s[i]);
            }
        }
        return resultStr;
    }
};


// Time Complexity -> O(n)
// Sapce Complexity -> O(n)

//-----------------------------------------------------------------------------------------------------

// --------- APPROACH - 2 ( traverse from both left to right once and right to left once) -------------

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string resultStr = "";
        int openParentheses = 0;

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                resultStr.push_back(s[i]);
            } else if (s[i] == '(') {
                openParentheses++;
                resultStr.push_back(s[i]);
            } else if(openParentheses > 0) {
                openParentheses--;
                resultStr.push_back(s[i]);
            }
        }

        string finalStr = "";
        int closeParentheses = 0;

        for(int i = resultStr.length() - 1; i >= 0; i--){
            if(resultStr[i] >= 'a' && resultStr[i] <= 'z'){
                finalStr.push_back(resultStr[i]);
            } else if (resultStr[i] == ')'){
                closeParentheses++;
                finalStr.push_back(resultStr[i]);
            } else if (closeParentheses > 0) {
                closeParentheses--;
                finalStr.push_back(resultStr[i]);
            }
        }

        reverse(finalStr.begin(), finalStr.end());
        return finalStr;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------------
