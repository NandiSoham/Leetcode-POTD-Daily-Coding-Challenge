// Problem Link -> https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int deletionCount = 0;
        stack<char> charSt;

        for(int i = 0; i < n; i++){
            if(!charSt.empty() && s[i] == 'a' && charSt.top() == 'b'){
                charSt.pop();
                deletionCount++;
            } else {
                charSt.push(s[i]);
            }
        }

        return deletionCount;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
