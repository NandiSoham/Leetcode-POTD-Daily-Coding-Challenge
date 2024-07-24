// Problem Link -> https://leetcode.com/problems/sort-the-jumbled-numbers/description/

class Solution {
public:

    string convertToMappedStr(string &number, vector<int>& mapping){
        string mappedStr = "";
        for(char &digit : number){
            mappedStr += to_string(mapping[digit - '0']);
        }

        return mappedStr;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mappedNumIdxPair;

        for(int i = 0; i < n; i++){
            string originalNumStr = to_string(nums[i]);
            string mappedNumStr = convertToMappedStr(originalNumStr, mapping);
            int mappedNum = stoi(mappedNumStr);

            mappedNumIdxPair.push_back({mappedNum, i});
        }

        sort(mappedNumIdxPair.begin(), mappedNumIdxPair.end());

        vector<int> ans;
        for(auto &pair : mappedNumIdxPair){
            int originalIdx = pair.second;
            ans.push_back(nums[originalIdx]);
        }

        return ans;
    }
};



// Time Complexity -> O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
// Space Complexity -> O(n+d)
