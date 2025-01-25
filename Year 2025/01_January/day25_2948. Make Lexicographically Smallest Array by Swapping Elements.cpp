// Problem Link -> https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

// ======================================= Approach - 1 (TLE issue) ====================================

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (true) {
                int smallerVal = nums[i];
                int idx = -1;

                for (int j = i + 1; j < n; j++) {
                    if (abs(nums[i] - nums[j]) <= limit && nums[j] < smallerVal) {
                        smallerVal = nums[j];
                        idx = j;
                    }
                }

                if (idx != -1) {
                    swap(nums[i], nums[idx]);
                } else break;
            }
        }

        return nums;
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(1)

// =========================================================================================
