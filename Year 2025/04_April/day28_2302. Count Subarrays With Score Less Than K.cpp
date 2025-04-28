// Problem Link -> https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long count = 0;
        long long currSum = 0;

        int windowStart = 0;
        int windowEnd = 0;

        while (windowEnd < n) {
            currSum += nums[windowEnd];

            while (windowStart <= windowEnd &&
                   currSum * (windowEnd - windowStart + 1) >= k) {
                currSum -= nums[windowStart];
                windowStart++;
            }

            count += (windowEnd - windowStart + 1);
            windowEnd++;
        }

        return count;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
