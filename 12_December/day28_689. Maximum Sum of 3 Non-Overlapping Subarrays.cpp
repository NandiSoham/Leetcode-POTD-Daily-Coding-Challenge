// Problem Link -> https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

class Solution {
private:
    int memo[20001][4];

    int calculateMaxSum(vector<int>& subarraySums, int subarrayLength, int currentIndex, int remainingSubarrays) {
        if (remainingSubarrays == 0) return 0;
        if (currentIndex >= subarraySums.size()) {
            return INT_MIN;
        }

        if (memo[currentIndex][remainingSubarrays] != -1) {
            return memo[currentIndex][remainingSubarrays];
        }

        int includeCurrent = subarraySums[currentIndex] + calculateMaxSum(subarraySums, subarrayLength, currentIndex + subarrayLength, remainingSubarrays - 1);
        int excludeCurrent = calculateMaxSum(subarraySums, subarrayLength, currentIndex + 1, remainingSubarrays);

        memo[currentIndex][remainingSubarrays] = max(includeCurrent, excludeCurrent);
        return memo[currentIndex][remainingSubarrays];
    }

    void findSubarrayIndices(vector<int>& subarraySums, int subarrayLength, int currentIndex, int remainingSubarrays, vector<int>& resultIndices) {
        if (remainingSubarrays == 0) return;
        if (currentIndex >= subarraySums.size()) return;

        int includeCurrent = subarraySums[currentIndex] + calculateMaxSum(subarraySums, subarrayLength, currentIndex + subarrayLength, remainingSubarrays - 1);
        int excludeCurrent = calculateMaxSum(subarraySums, subarrayLength, currentIndex + 1, remainingSubarrays);

        if (includeCurrent >= excludeCurrent) {
            resultIndices.push_back(currentIndex);
            findSubarrayIndices(subarraySums, subarrayLength, currentIndex + subarrayLength, remainingSubarrays - 1, resultIndices);
        } else {
            findSubarrayIndices(subarraySums, subarrayLength, currentIndex + 1, remainingSubarrays, resultIndices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(memo, -1, sizeof(memo));

        int numPossibleSubarrays = nums.size() - k + 1;
        vector<int> subarraySums;
        int currentWindowSum = 0;
        int start = 0, end = 0;

        while (end < nums.size()) {
            currentWindowSum += nums[end];
            if (end - start + 1 == k) {
                subarraySums.push_back(currentWindowSum);
                currentWindowSum -= nums[start];
                start++;
            }
            end++;
        }

        vector<int> resultIndices;
        findSubarrayIndices(subarraySums, k, 0, 3, resultIndices);

        return resultIndices;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
