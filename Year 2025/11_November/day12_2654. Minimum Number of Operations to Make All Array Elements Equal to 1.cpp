// problem link -> https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
                count1++;
        }

        if(count1 > 0) {
            return n - count1;
        }

        int minStepsTo1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            int GCD = nums[i];

            for(int j = i+1; j < n; j++) {
                
                GCD = gcd(GCD, nums[j]);
                
                if(GCD == 1) {
                    minStepsTo1 = min(minStepsTo1, j-i);
                    break;
                }
            }
        }

        if(minStepsTo1 == INT_MAX) {
            return -1;
        }
        return minStepsTo1 + (n-1);
    }
};



// Time Complexity -> O(n² × log(max(nums)))
// Space Complexity -> O(1)
