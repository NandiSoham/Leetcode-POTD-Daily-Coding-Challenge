// Problem Link -> https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

// ============================== Approach - 1 ==============================

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int idx = 0;

        while(idx < n){
            long long zerosCount = 0;

            if(nums[idx] == 0){
                while(idx < n && nums[idx] == 0){
                    idx++;
                    zerosCount++;
                }
            } else idx++;

            ans += (zerosCount * (zerosCount + 1)) / 2;
        }
        
        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// ==========================================================================


// ============================== Approach - 2 ==============================

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int contZero = 0;
        int n = nums.size();
        
        for (int it : nums) {
            if(it == 0){
                contZero++;
            } else {
                contZero = 0;
            }
            count += contZero;
        }
        
        return count;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// ==========================================================================
