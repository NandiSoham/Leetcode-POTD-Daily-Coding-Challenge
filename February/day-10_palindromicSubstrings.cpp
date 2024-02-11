class Solution {
public:
    int t[1001][1001];

    bool checkPalindrome(string &s, int i, int j){
        if(i > j) return true;
            
        if(s[i] == s[j]){
            return t[i][j] = checkPalindrome(s, i+1, j-1);
        }
        return t[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(checkPalindrome(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};


//Time Complexity : O(n^2)
//Space Complexity : O(n^2)
//Problem Link: https://leetcode.com/problems/palindromic-substrings/description/
