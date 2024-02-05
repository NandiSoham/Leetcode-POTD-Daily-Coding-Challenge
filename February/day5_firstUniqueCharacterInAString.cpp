class Solution {
public:
    int firstUniqChar(string s) {
        int freqArr[26] = {0};

        for(char ch : s){
            freqArr[ch - 'a']++;
        }

        for(int  i =0 ; i < s.length(); i++){
            if(freqArr[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1;
    }
};


// Time Complexity -> O(n)
// Space Complexity - > O(1)
// Problem Link - > https://leetcode.com/problems/first-unique-character-in-a-string/
