// Problem Link -> https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    void findCombination(int idx, vector<int>& candidates, int target,
                         vector<int> storeComb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(storeComb);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            storeComb.push_back(candidates[i]);
            findCombination(i + 1, candidates, target - candidates[i], storeComb, ans);
            storeComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> storeComb;
        vector<vector<int>> ans;
        findCombination(0, candidates, target, storeComb, ans);
        return ans;
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)
