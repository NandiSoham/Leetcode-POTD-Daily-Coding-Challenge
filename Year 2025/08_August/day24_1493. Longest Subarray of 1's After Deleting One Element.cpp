// Problem Link -> https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroCount = 0;
        int longestSubarr = 0;

        for(int right = 0; right < nums.size(); right++){
            
            if(nums[right] == 0) zeroCount++;

            while(zeroCount > 1){
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            longestSubarr = max(longestSubarr, right - left);
        }

        return longestSubarr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
