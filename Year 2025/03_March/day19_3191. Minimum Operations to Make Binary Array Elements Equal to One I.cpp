// Problem Link -> https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operationCount = 0;

        for(int i = 0; i < n - 2; i++){
            if(nums[i] == 0){
                nums[i] = nums[i] == 0 ? 1 : 0;
                nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
                nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;

                operationCount++;
            }
        }

        if(nums[n - 1] == 0 || nums[n - 2] == 0)
            return -1;
        
        return operationCount;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
