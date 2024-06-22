// Problem Link -> https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// --------------------------------------- Approach - 1 ----------------------------------------

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0, prevCount = 0;
        int result = 0;

        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] % 2 != 0) {
                oddCount++;
                prevCount = 0;
            }

            while (oddCount == k) {
                prevCount++;
                if (i < n && nums[i] % 2 == 1)
                    oddCount--;
                i++;
            }
            j++;
            result += prevCount;
        }

        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// ---------------------------------------------------------------------------------------------
