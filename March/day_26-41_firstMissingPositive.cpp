// Problem Link -> https://leetcode.com/problems/first-missing-positive/description/

// ----------------------------- Approcha -1 -> Using Sorting ----------------------------------

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;

        while(i < n && nums[i] <= 0) i++;

        int missingPositive = 1;

        for(int j = i; j < n; j++){
            if (missingPositive == nums[j])
                missingPositive = missingPositive + 1;
                else if (nums[j] > missingPositive)

                return missingPositive;
        }

        return missingPositive;   
    }
};


// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------------
