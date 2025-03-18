// Problem Link -> https://leetcode.com/problems/longest-nice-subarray/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool isNiceSubArr(int i, int j, vector<int>& nums){
        int bitMask = 0;
        for(int k = i; k <= j; k++){
            if ((bitMask & nums[k]) != 0){
                return false;
            }
            bitMask |= nums[k];
        }

        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isNiceSubArr(i, j, nums)){
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }
};


// Time Complexity -> O(n ^ 3)
// Space Complexity -> O(1)

// =============================================================================================================
