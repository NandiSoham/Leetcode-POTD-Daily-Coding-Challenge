// Problem Link -> https://leetcode.com/problems/valid-word/description/

class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool isVowel = false;
        bool isConsonant = false;

        for(char ch : word){
            if(isalpha(ch)){
                ch = tolower(ch);

                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    isVowel = true;
                } else isConsonant = true;
            }

            else if(!isdigit(ch)) return false;
        }

        return isVowel && isConsonant;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
