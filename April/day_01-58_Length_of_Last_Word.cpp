// Problem Link -> https://leetcode.com/problems/length-of-last-word/description/

// ---------------------------------------- Approach -1 ---------------------------------------

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int  i = n - 1;
        int ansLength = 0;

        while(i >= 0 && s[i] == ' '){
            i--;
        }
        
        while(i >= 0 && s[i] != ' '){
            i--;
            ansLength ++;
        }
        return ansLength;
    }
};


// Time Complexity -> O(n)
//Space Complexity -> O(1)

// --------------------------------------------------------------------------------------------
