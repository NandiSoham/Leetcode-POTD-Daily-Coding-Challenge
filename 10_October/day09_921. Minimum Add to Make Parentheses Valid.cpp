// Problem Link -> https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string parenthesesStr) {
        int unmatchedOpenBrackets = 0; 
        int unmatchedCloseBrackets = 0; 

        for(char &currentChar : parenthesesStr) {
            if(currentChar == '(') {
                unmatchedOpenBrackets++; 
            } else if(unmatchedOpenBrackets > 0) {
                unmatchedOpenBrackets--;  
            } else {
                unmatchedCloseBrackets++; 
            }
        }

        return unmatchedCloseBrackets + unmatchedOpenBrackets;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
