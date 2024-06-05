// Problem Link -> https://leetcode.com/problems/find-common-characters/description/

class Solution {
public:
    void fillCount(string& word, int countArr[26]){
        for(char &ch : word){
            countArr[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        int countArr[26] = {0};

        fillCount(words[0], countArr);

        for(int i = 1; i < n; i++){
            int tempArr[26] = {0};
            fillCount(words[i], tempArr);

            for(int j = 0; j < 26; j++){
                countArr[j] = min(countArr[j], tempArr[j]);
            }
        }

        for(int i = 0; i < 26; i++){
            int count = countArr[i];
            while(count--){
                ans.push_back(string(1, i + 'a'));
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n*m)  [ where n = number of words and m = average length of each word]
// Space Complexity -> O(1)
