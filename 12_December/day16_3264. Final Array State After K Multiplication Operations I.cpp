// Problem Link -> https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while(k--){
            int currMin = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] < nums[currMin]){
                    currMin = i;
                }
            }

            nums[currMin] *= multiplier;
        }

        return nums;
    }
};


// Time Complexity -> O(kn)
// Space Complexity -> O(1)
