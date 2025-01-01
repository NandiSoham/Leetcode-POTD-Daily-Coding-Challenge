// problem Link -> https://leetcode.com/problems/patching-array/description/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int idx = 0;
        int patchCount = 0;
        long maxReach = 0;

        while(maxReach < n){
            if(idx < nums.size() && nums[idx] <= maxReach + 1){
                maxReach += nums[idx];
                idx++;
            } else {
                maxReach += maxReach + 1;
                patchCount++;
            }
        }

        return patchCount;
    }
};
