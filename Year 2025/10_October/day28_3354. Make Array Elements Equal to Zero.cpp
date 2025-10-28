// Problem Link -> https://leetcode.com/problems/make-array-elements-equal-to-zero/description/

// ==================================== Approach - 1 ===================================

class Solution {
public:

    bool canMakeAllZero(vector<int>& nums, int idx, int count, int direction){
        vector<int> temp = nums;
        int curr = idx;

        while(curr >= 0 && curr < nums.size() && count > 0){
            if(temp[curr] > 0){
                temp[curr]--;
                direction *= -1;

                if(temp[curr] == 0) count--;
            }

            curr += direction;
        }

        return count == 0;
    }
    
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, count = 0;

        for (int val : nums)
            if (val != 0) count++;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (canMakeAllZero(nums, i, count, -1))
                    ans++;

                if (canMakeAllZero(nums, i, count, 1))
                    ans++;
            }
        }

        return ans;
    }
};


// Time Complexity -> O(n^2 *m)
// Space Complexity -> O(n)

// =====================================================================================
