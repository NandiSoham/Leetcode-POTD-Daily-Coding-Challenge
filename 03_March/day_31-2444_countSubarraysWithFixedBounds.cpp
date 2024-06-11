class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKIndex = -1, maxKIndex = -1;
        int culpritElementIndex = -1;

        long long result = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK) culpritElementIndex = i;

            if(nums[i] == minK) minKIndex = i;

            if(nums[i] == maxK)maxKIndex = i;

            int smallerElementIdx = min(minKIndex, maxKIndex);
            long long tempResult = smallerElementIdx - culpritElementIndex;

            if(tempResult <= 0)
                result += 0;
            else
                result += tempResult;
        }
        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
