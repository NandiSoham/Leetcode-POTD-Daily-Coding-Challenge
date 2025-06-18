// Problem Link -> https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> maxDiffArr;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                maxDiffArr.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else return {};
        }

        return maxDiffArr;
    }
};


// Time COmplexity -> O(n logn )
// SPace Complexity -> O(1)
