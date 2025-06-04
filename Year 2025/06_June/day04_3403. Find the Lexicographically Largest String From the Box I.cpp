// Problem Link -> https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if(numFriends == 1) return word;

        int longestPossilbe = n - (numFriends - 1);
        string ans;

        for(int i = 0; i < n; i++){
            int canTakeLen = min(longestPossilbe, n - i);
            ans = max(ans, word.substr(i, canTakeLen));
        }

        return ans;
    }
};


// time Complexity -> O(n ^ 2)
// Space COmplexity -> O(1)
