// Problem Link -> https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

class Solution {
public:

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> subsetMap;
        int ans = solve(0, nums, subsetMap, k);
        return ans - 1;
    }

    int solve(int idx, vector<int>& nums, unordered_map<int, int>& subsetMap,
              int k) {
        if (idx >= nums.size())
            return 1;

        int count = 0;

        // take
        if (!subsetMap[nums[idx] - k] && !subsetMap[nums[idx] + k]) {
            subsetMap[nums[idx]]++;
            count += solve(idx + 1, nums, subsetMap, k);
            subsetMap[nums[idx]]--;
        }

        // not take
        count += solve(idx + 1, nums, subsetMap, k);

        return count;
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)
