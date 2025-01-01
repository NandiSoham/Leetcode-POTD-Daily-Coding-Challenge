// Problem Link -> https://leetcode.com/problems/subsets/description/

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsetArr;
        vector<vector<int>> ans;
        solve(nums, 0, subsetArr, ans);
        return ans;
    }

    void solve(vector<int>& nums, int idx, vector<int>& subsetArr,
               vector<vector<int>>& ans) {
        if (idx >= nums.size()) {
            ans.push_back(subsetArr);
            return;
        }

        // take
        subsetArr.push_back(nums[idx]);
        solve(nums, idx + 1, subsetArr, ans);

        // not take
        subsetArr.pop_back();
        solve(nums, idx + 1, subsetArr, ans);
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(2^n*length of each subset)
