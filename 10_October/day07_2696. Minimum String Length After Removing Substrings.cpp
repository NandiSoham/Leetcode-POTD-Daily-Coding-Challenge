// Problem Link -> https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

class Solution {
public:
    int minLength(string inputStr) {
        stack<char> charStack;

        for (int i = 0; i < inputStr.length(); i++) {
            char currentChar = inputStr[i];

            if (charStack.empty()) {
                charStack.push(currentChar);
                continue;
            }

            if (currentChar == 'B' && charStack.top() == 'A') {
                charStack.pop();
            } 
            else if (currentChar == 'D' && charStack.top() == 'C') {
                charStack.pop();
            } 
            else {
                charStack.push(currentChar);
            }
        }

        return charStack.size();
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(1)
