// Problem Link -> https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            for(int j = i+1; j < nums.size();j++){
                if(nums[j] == - nums[i]){
                    result = max(result, abs(nums[i]));
                }
            }
        }
        return result;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------

