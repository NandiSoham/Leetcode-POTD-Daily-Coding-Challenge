// Problem Link -> https://leetcode.com/problems/reverse-prefix-of-word/description/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        int i = 0;
        while(i < idx){
            swap(word[i], word[idx]);
            i++;
            idx--;
        }
        return word;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------

// ---------------------------------------- Approach - 2  ---------------------------------------

class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), word.begin()+word.find(ch)+1);
        return word;
        
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------
