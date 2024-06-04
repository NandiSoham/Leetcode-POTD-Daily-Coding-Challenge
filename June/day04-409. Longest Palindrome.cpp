// Problem Link -> https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<char> charSet;
        int ans = 0;

        for(char &ch : s){
            if(charSet.find(ch) != charSet.end()){
                ans += 2;
                charSet.erase(ch);
            } else {
                charSet.insert(ch);
            }
        }
        if(!charSet.empty()) ans++;

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
