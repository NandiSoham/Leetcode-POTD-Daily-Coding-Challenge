// Problem Link -> https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/

// ======================================= Approach - 1 (TLE) ====================================

class Solution {
public:
    int findDigSum(int num){
        int sum = 0; 

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int digSum_i = findDigSum(nums[i]);

            for (int j = i + 1; j < n; j++) {
                int digSum_j = findDigSum(nums[j]);

                if(digSum_i == digSum_j){
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }

        return ans;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(1)

// =========================================================================================
