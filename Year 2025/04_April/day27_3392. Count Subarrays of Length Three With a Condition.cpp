// Problem Link -> https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 1; i < n - 1; i++){
            if(nums[i] == (nums[i - 1] + nums[i + 1]) * 2){
                count++;
            }
        }

        return count;
    }
};


// Time complexity -> O(n)
// Space complexity -> O(1)
