// Problem Link -> https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]) {
                int incrementAmount = nums[i - 1] - nums[i] + 1;
                nums[i] += incrementAmount;
                result += incrementAmount;
            }
        }

        return result;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
