// Problem Link -> https://leetcode.com/problems/find-the-original-typed-string-i/description/

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int countPossibleStr = 0;

        for(int i = 1; i < n; i++){
            if(word[i] == word[i - 1])
                countPossibleStr++;
        }

        return countPossibleStr + 1;
    }
};


// Time Complexity -> O(n)
// SPace complexity -> O(1)
