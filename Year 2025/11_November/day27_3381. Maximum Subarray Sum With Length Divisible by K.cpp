// Problem Link -> https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        long long best = LLONG_MIN;

        for (int start = 0; start < k; start++) {
            long long running = 0;
            int i = start;

            while (i + k - 1 < n) {
                int end = i + k - 1;

                long long chunkSum = prefix[end] - (i > 0 ? prefix[i - 1] : 0);

                running = max(chunkSum, running + chunkSum);
                best = max(best, running);

                i += k;
            }
        }

        return best;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
