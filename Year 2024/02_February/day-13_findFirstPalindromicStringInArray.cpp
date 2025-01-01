class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &word : words){
            string reverseWord (word.rbegin() , word.rend());
            if(word == reverseWord) return word;
        }
        return "";
    }
};


// Time Complexity -> O(M*N) -> M = number of words, N = max length length of words
// Space Complexity -> O(N) -> as we're creating reverse string of size N
//Problem Statement -> https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
