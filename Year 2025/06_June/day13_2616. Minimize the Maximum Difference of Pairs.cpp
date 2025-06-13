// Problem Link -> https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution {
public:
    int n;
    
    bool checkValid(vector<int>& nums, int maxDiff, int requiredPairs) {
        int idx = 0;
        int pairCount = 0;
        
        while(idx < n - 1) {
            if(nums[idx + 1] - nums[idx] <= maxDiff) {
                pairCount++;
                idx += 2;
            } else {
                idx++;
            }
        }
        
        return pairCount >= requiredPairs;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int low = 0;
        int high = nums[n - 1] - nums[0];
        
        int minMaxDiff = INT_MAX;
        
        while(low <= high) {
            int midDiff = low + (high - low) / 2;
            
            if(checkValid(nums, midDiff, p)) {
                minMaxDiff = midDiff;
                high = midDiff - 1;
            } else {
                low = midDiff + 1;
            }
        }
        
        return minMaxDiff;
    }
};
