// Problem Link -> https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int length = 0;
        int powVal = 1;  // 2^0

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') length++;
            else if(powVal <= k){
                k -= powVal;
                length++;
            }

            if(powVal <= k){
                powVal = powVal * 2;    // powval <<= 1
            }
        }

        return length;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
