// Problem Link -> https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int sIdx = 0, tIdx = 0;
        int sLen = s.length();
        int tLen = t.length();

        while(sIdx < sLen && tIdx <tLen){
            if(s[sIdx] == t[tIdx]){
                sIdx++;
                tIdx++;
            } else {
                sIdx++;
            }
        }
        return tLen - tIdx;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
