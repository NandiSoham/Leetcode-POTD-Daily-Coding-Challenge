// Problem link -> https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int prevMin = nums[0];

        for (int i = 0; i < n; i++) {
            if(nums[i] > prevMin){
                maxDiff = max(maxDiff, (nums[i] - prevMin));
            } else {
                prevMin = nums[i];
            }
        }

        return maxDiff;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
