// Problem Link -> https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

// ---------------------------------------- Brute Force Approach ---------------------------------------

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& currSubset,
                         vector<vector<int>>& subsets) {

        if (i == nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i + 1, currSubset, subsets);
        currSubset.pop_back();
        solve(nums, i + 1, currSubset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        solve(nums, 0, currSubset, subsets);

        int result = 0;
        for (auto& currSubset : subsets) {
            int Xor = 0;
            for (int num : currSubset) {
                Xor ^= num;
            }
            result += Xor;
        }
        return result;
    }
};


// Time Complexity -> O(n * 2^n)
// Space Complexity -> O(n * 2^n)

//-----------------------------------------------------------------------------------------------

// ---------------------------------------- Better Approach ---------------------------------------

class Solution {
public:
    int solve(vector<int>& nums, int i, int xorVal) {

        if (i == nums.size()) {
            return xorVal;
        }

        int inc = solve(nums, i + 1, nums[i] ^ xorVal);
        int exc = solve(nums, i + 1, xorVal);

        return inc + exc;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------
