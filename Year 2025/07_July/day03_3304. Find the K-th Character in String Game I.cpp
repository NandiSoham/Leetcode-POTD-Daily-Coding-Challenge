// Problem link -> https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k){
            int n = word.length();

            for(int i = 0; i < n; i++){
                char nextChar;

                if(word[i] == 'z') nextChar = 'a';
                nextChar = word[i] + 1;

                word.push_back(nextChar);
            }
        }

        return word[k - 1];
    }
};


// ======================= Alternate/ Smarter Way to write the same logic =================

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k){
            int n = word.length();

            for(int i = 0; i < n; i++){
                char ch = word[i] == 'z' ? 'a' : word[i]+1;
                word.push_back(ch);
            }
        }

        return word[k - 1];
    }
};



// Time Complexity -> O(k)
// Space Complexity -> O(k)
