// Problem Link -> https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int arraySize = nums.size();

        vector<int> result(arraySize - k + 1, -1);
        int consecutiveCount = 1; 

        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }
        }

        if (consecutiveCount == k) {
            result[0] = nums[k - 1];
        }
        int windowStart = 1;
        int windowEnd = k;

        while (windowEnd < arraySize) {
            if (nums[windowEnd] == nums[windowEnd - 1] + 1) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }

            if (consecutiveCount >= k) {
                result[windowStart] = nums[windowEnd];
            }
            windowStart++;
            windowEnd++;
        }

        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
