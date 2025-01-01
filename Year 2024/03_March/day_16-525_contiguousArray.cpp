class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int currentSum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            currentSum += (nums[i] == 1) ? 1 : -1;
            if(mpp.find(currentSum) != mpp.end()){
                ans = max(ans, i - mpp[currentSum]);
            } else{
                mpp[currentSum] = i;
            }
        }
        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/contiguous-array/
