// Problem Link -> https://leetcode.com/problems/find-words-containing-character/description/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ansArr;
        int n = words.size();

        for(int i = 0; i < n; i++){
            if(words[i].find(x) != string::npos){
                ansArr.push_back(i);
            }
        }

        return ansArr;
    }
};


// Time Complexity -> O(m * n)
// Space Complexity -> O(1)
