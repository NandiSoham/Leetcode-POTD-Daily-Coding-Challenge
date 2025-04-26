// Problem Link -> https://leetcode.com/problems/count-largest-group/description/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        
        int minIdx = -1;
        int maxIdx = -1;
        int leftBound = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if(nums[i] == minK)
                minIdx = i;
            if(nums[i] == maxK)
                maxIdx = i;
            
            int validSubarrays = min(maxIdx, minIdx) - leftBound;
            
            count += (validSubarrays <= 0) ? 0 : validSubarrays;
            
        }
        
        return count;
    }
};


// Tiem complexity -> O(n)
// Space Complexity -> O(1)
