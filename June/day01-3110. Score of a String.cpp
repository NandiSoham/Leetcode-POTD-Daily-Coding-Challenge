// Problem Link -> https://leetcode.com/problems/score-of-a-string/description/

class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int score = 0;

        for(int i = 0; i < n-1; i++){
            score += abs(s[i] - s[i+1]);;
        }
        return score;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
