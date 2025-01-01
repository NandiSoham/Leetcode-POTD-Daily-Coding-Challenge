// Problem Link -> https://leetcode.com/problems/custom-sort-string/description/

//-------------------------- Approach - 1 -----------------------------------------

class Solution {
public:
    string customSortString(string order, string s) {
        int count[26] = {0};
        string answer = "";

        for(char &ch : s){
            count[ch - 'a']++;
        }

        for(char &ch : order){
            while(count[ch - 'a'] > 0){
                answer.push_back(ch);
                count[ch - 'a']--;
            }
        }

        for(char &ch : s){
            if(count[ch - 'a'] >0){
                answer.push_back(ch);
            }
        }
        return answer;
    }
};


// Time Complexity -> O(n), where n = length of the given string
// Space Complexity -> O(1)

//---------------------------------------------------------------------------------
