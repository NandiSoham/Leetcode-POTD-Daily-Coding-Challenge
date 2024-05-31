// Problem Link -> https://leetcode.com/problems/single-number-iii/description/

// ---------------------------------------- Brute Force ----------------------------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int currCount = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    currCount++;
            }
            if(currCount == 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------------------------
