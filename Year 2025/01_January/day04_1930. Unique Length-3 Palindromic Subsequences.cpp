// Problem Link -> https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int totalCount = 0;

        unordered_set<char> distinctLetters;
        for(char &ch : s){
            distinctLetters.insert(ch);
        }

        for(char currentLetter : distinctLetters){
            int firstIdx = -1;
            int lastIdx = -1;

            for(int i = 0; i < n; i++){
                if(s[i] == currentLetter){

                    if (firstIdx == -1){
                        firstIdx = i;
                    }
                    
                    lastIdx = i;
                }
            }

            unordered_set<char> middleChars;
            for(int middleIdx = firstIdx + 1; middleIdx <= lastIdx - 1; middleIdx++){
                middleChars.insert(s[middleIdx]);
            }

            totalCount += middleChars.size();
        }

        return totalCount;
    }
};



// Time Complexity: O (n)
//Space Complexity: O (1)

// =========================================================================================


// ======================================= Approach - 1 ====================================

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int totalCount = 0;

        vector<pair<int, int>> charIndices(26, {-1, -1});
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            int currIdx = currChar - 'a';

            if (charIndices[currIdx].first == -1) {
                charIndices[currIdx].first = i;
            }
            charIndices[currIdx].second = i;
        }

        for (int i = 0; i < 26; i++) {
            int firstIdx = charIndices[i].first;
            int lastIdx = charIndices[i].second;

            unordered_set<char> middleChars;
            for (int middleIdx = firstIdx + 1; middleIdx <= lastIdx - 1;
                 middleIdx++) {
                middleChars.insert(s[middleIdx]);
            }

            totalCount += middleChars.size();
        }

        return totalCount;
    }
};


// Time Complexity: O (n)
//Space Complexity: O (1)

// =========================================================================================
