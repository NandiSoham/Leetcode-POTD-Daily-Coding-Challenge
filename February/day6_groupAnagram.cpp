class Solution {
public:
    string generate(string &word){
        int arr[26] = {0};
        for(char ch : word){
            arr[ch - 'a']++;
        }
        string new_word = "";
        for(int i = 0; i < 26; i++){
            int freq = arr[i];
            if(freq > 0)
                new_word += string(freq, i+'a');
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map <string, vector<string>> mpp;
        vector<vector<string>> result;
        for(int i = 0; i<n; i++){
            string word = strs[i];
            string new_word = generate(word);
            mpp[new_word].push_back(word);
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};



//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
//Problem link: https://leetcode.com/problems/group-anagrams/description/
