// Problem Link -> https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt = 1;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int prev = nums[0] - k;

        for (int i = 1; i < n; i++) {

            int currMin = max(prev + 1, nums[i] - k);
            if (currMin <= nums[i] + k) {
                cnt++;
                prev = currMin;
            } else {
                prev = nums[i] + k;
            }
        }

        return cnt;
    }
};


// Time Complexity -> O(n log n)
// Space Complexity -> O(1)
