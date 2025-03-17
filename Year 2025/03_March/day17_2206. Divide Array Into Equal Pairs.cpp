// Problem Link -> https://leetcode.com/problems/divide-array-into-equal-pairs/description/

// ======================================= Approach - 1 (Sorting) ====================================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i+= 2){
            if(nums[i] != nums[i + 1]){
                return false;
            }
        }

        return true;
    }
};


// Time Complexity -> O(n logn)
// Space Complexity -> O(1)

// =============================================================================================================
