// Problem Link -> https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smallerElements;
        vector<int> equalElements;
        vector<int> largerElements;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) smallerElements.push_back(nums[i]);
            else if (nums[i] == pivot) equalElements.push_back(nums[i]);
            else largerElements.push_back(nums[i]);
        }

        for(int i = 0; i < equalElements.size(); i++){
            smallerElements.push_back(equalElements[i]);
        }

        for(int i = 0; i < largerElements.size(); i++){
            smallerElements.push_back(largerElements[i]);
        }

        return smallerElements;
    }
};


// Time Complexity -> O (n)
// Space Complexity -> O (n)

// =========================================================================================
