class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n-1;

        while(i < j && s[i] == s[j]){
            char ch = s[i];

            while(i < j && s[i] == ch) i++;
            while(j >= i && s[j] == ch) j--;
        }
        int lenOfMinStringAfterDeleting = j - i + 1;
        return lenOfMinStringAfterDeleting;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
