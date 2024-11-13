// Problem Link -> https://leetcode.com/problems/count-the-number-of-fair-pairs/description/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(begin(nums), end(nums)); 
        long long result = 0;

        for (int i = 0; i < n; i++) { 
            int startIdx = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums);
            int x = startIdx - 1 - i;
            int endIdx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums);
            int y = endIdx - 1 - i;
            result += (y - x);
        }

        return result;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
