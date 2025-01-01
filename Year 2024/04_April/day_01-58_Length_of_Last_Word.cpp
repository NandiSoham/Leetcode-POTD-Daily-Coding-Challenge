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

// ------------------------------ Approach - 2 ( Using STL) -----------------------------------

class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ') + 1);
        int lastSpace = s.find_last_of(' ');
        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

// --------------------------------------------------------------------------------------------
