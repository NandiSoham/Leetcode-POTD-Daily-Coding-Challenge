// Problem Link -> https://leetcode.com/problems/make-sum-divisible-by-p/description/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSumModP = 0;

        for (int &num : nums) {
            totalSumModP = (totalSumModP + num) % p;
        }

        int targetRemainder = totalSumModP % p;

        if (targetRemainder == 0) {
            return 0; 
        }

        unordered_map<int, int> modPrefixSumIndex; 
        modPrefixSumIndex[0] = -1; 

        int currentPrefixSumModP = 0;
        int minSubarrayLength = n; 

        for (int j = 0; j < n; j++) {
            currentPrefixSumModP = (currentPrefixSumModP + nums[j]) % p;

            int requiredRemainder = (currentPrefixSumModP - targetRemainder + p) % p;

            if (modPrefixSumIndex.find(requiredRemainder) != modPrefixSumIndex.end()) {
                minSubarrayLength = min(minSubarrayLength, j - modPrefixSumIndex[requiredRemainder]);
            }

            modPrefixSumIndex[currentPrefixSumModP] = j;
        }

        return minSubarrayLength == n ? -1 : minSubarrayLength;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
