// Problem Link -> https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/

class Solution {
public:
    bool isAnagram(string &str1, string &str2){
        int arr[26] = {0};

        for(char &ch : str1){
            arr[ch - 'a']++;
        }

        for(char &ch : str2){
            arr[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);  

        for(int i = 1; i < n; i++){
            if(!isAnagram(words[i], ans.back())){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};


// Time Complexity -> O(m * n)
// Space Complexity -> O(1)
