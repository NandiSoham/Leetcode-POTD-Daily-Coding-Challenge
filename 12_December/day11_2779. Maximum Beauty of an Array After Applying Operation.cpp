// Problem Link -> https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, maxBeauty = 0;

        for (int right = 0; right < n; ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            maxBeauty = max(maxBeauty, right - left + 1);
        }

        return maxBeauty;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
