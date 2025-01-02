// Problem Link -> https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

class Solution {
public:

    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int sizeOfWords = words.size();
        int sizeOfQueries = queries.size();
        vector<int> cumSum(sizeOfWords);
        int vowelPairCount = 0;
        vector<int> resultArr(sizeOfQueries);

        for(int i = 0; i < sizeOfWords; i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                vowelPairCount++;
            }

            cumSum[i] = vowelPairCount;
        }

        for(int i = 0; i < sizeOfQueries; i++){
            int left = queries[i][0];
            int right = queries[i][1];

            resultArr[i] = (cumSum[right] - ((left > 0) ? cumSum[left - 1] : 0));
        }

        return resultArr;
    }
};




// Time Complexity -> O(sizeOfWords + sizeOfQueries)
// Space Complexity -> O(sizeOfQueries)
