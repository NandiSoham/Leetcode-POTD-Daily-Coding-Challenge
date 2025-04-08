// Problem Link -> https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> elementSet;

        for(int i = nums.size() - 1; i >= 0; i--){
            if(elementSet.count(nums[i])){
                return ceil((i + 1) / 3.0);
            }

            elementSet.insert(nums[i]);
        }

        return 0;
    }
};


// Time complexity -> O(n)
// Space Complexity -> O(n)
