// Problem Link -> https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int leftPointer = 0, rightPointer = 0;
        long long maxSum = 0;
        long long currentWindowSum = 0;
        unordered_set<int> uniqueElements;

        while (rightPointer < nums.size()) {
            while (uniqueElements.count(nums[rightPointer])) {
                currentWindowSum -= nums[leftPointer];
                uniqueElements.erase(nums[leftPointer]);
                leftPointer++;
            }

            currentWindowSum += nums[rightPointer];
            uniqueElements.insert(nums[rightPointer]);

            if (rightPointer - leftPointer + 1 == k) {
                maxSum = max(maxSum, currentWindowSum);
                currentWindowSum -= nums[leftPointer];
                uniqueElements.erase(nums[leftPointer]);
                leftPointer++;
            }
            rightPointer++;
        }

        return maxSum;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
