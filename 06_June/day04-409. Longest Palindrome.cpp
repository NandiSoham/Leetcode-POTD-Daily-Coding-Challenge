// Problem Link -> https://leetcode.com/problems/longest-palindrome/description/

// ------------------------------- APPROACH -1 --------------------------

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

//-----------------------------------------------------------------------


// ------------------------------- APPROACH - 2 --------------------------

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result  = 0;
        int oddFrq  = 0;

        for(char &ch : s) {
            mp[ch]++;

            if(mp[ch] % 2 != 0) {
                oddFrq++;
            } else {
                oddFrq--;
            }
        }

        if(oddFrq > 0) {
            return n - oddFrq + 1;
        }

        return n;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------
