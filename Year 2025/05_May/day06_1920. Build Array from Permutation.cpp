// Problem Link -> https://leetcode.com/problems/build-array-from-permutation/description/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
