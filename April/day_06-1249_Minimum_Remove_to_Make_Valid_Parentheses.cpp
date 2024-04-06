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
