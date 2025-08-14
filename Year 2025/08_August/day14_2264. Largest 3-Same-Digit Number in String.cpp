// Problem Link -> https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char maxChar = ' ';

        for(int i = 0; i <= n - 3; i++){
            if(num[i] == num[i + 1] && num[i] == num[i + 2]){
                maxChar = max(maxChar, num[i]);
            }
        }

        if(maxChar == ' ') return "";
        return string(3, maxChar);
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
