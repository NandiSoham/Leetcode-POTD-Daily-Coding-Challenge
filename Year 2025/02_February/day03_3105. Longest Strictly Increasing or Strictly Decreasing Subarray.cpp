// Problem Link -> https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++){
            int currLen = 1;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[j - 1]) currLen++;
                else break;
            }

            maxLength = max(maxLength, currLen);
        }

        for(int i = 0; i < nums.size(); i++){
            int currLen = 1;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] < nums[j - 1]) currLen++;
                else break;
            }

            maxLength = max(maxLength, currLen);
        }

        return maxLength;
    }
};



// Time Complexity: O (n ^ 2)
// Space Complexity: O (1)

// ===============================================================================================
