// Problem Link -> https://leetcode.com/problems/sort-vowels-in-a-string/description/

// ================================= Approach - 1 =================================

class Solution {
public:

    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        int n = s.length();
        string temp;

        for(char &ch : s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }

        sort(temp.begin(), temp.end());
        int j = 0;

        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }

        return s;
    }
};


// Time Complexity -> O(n log(n))
// Space Complexity -> O(1)

// ================================================================================
