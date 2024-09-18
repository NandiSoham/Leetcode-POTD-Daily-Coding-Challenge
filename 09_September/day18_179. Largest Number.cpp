// Problem Link -> https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    static bool customComperator(string str1, string str2){
        string combination1 = str1 + str2;
        string combination2 = str2 + str1;
        return combination1 > combination2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> convertedArr;
        for(int i = 0; i < nums.size(); i++){
            convertedArr.push_back(to_string(nums[i]));
        }

        sort(convertedArr.begin(), convertedArr.end(), customComperator);
        string result = "";
        for(auto it : convertedArr){
            result += it;
        }

        if(convertedArr[0] == "0") return "0";
        return result;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
