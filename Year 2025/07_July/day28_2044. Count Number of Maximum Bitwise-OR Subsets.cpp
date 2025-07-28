// Problem link -> https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

class Solution {
public:
    int findSubsetsCount(int idx, int currOr, int maxOr, vector<int>& nums){
        if(idx == nums.size()){
            if(currOr == maxOr) return 1;
            else return 0;
        }

        //take
        int take = findSubsetsCount(idx + 1, currOr | nums[idx], maxOr, nums);

        // not take
        int notTake = findSubsetsCount(idx + 1, currOr, maxOr, nums);

        return take + notTake;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int currOr = 0, maxOr = 0;
        
        for(int &it : nums){
            maxOr |= it;
        }
        
        return findSubsetsCount(0, currOr, maxOr, nums);
    }
};


// time complexity -> O(2^n)
//space complexity -> O(1)
