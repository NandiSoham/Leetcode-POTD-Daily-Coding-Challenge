// Problem Link -> https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int totalSize = nums.size(); 
        int partitionSize = totalSize / 3;

        vector<long long> minLeftSum(totalSize, 0);
        vector<long long> maxRightSum(totalSize, 0);

        priority_queue<int> leftMaxHeap;
        long long sumLeft = 0;
        for (int i = 0; i < 2 * partitionSize; i++) {
            leftMaxHeap.push(nums[i]);
            sumLeft += nums[i];

            if (leftMaxHeap.size() > partitionSize) {
                sumLeft -= leftMaxHeap.top();
                leftMaxHeap.pop();
            }

            minLeftSum[i] = sumLeft;
        }

        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        long long sumRight = 0;
        for (int i = totalSize - 1; i >= partitionSize; i--) {
            rightMinHeap.push(nums[i]);
            sumRight += nums[i];

            if (rightMinHeap.size() > partitionSize) {
                sumRight -= rightMinHeap.top();
                rightMinHeap.pop();
            }

            maxRightSum[i] = sumRight;
        }

        long long minDiff = LLONG_MAX;
        for (int i = partitionSize - 1; i < 2 * partitionSize; i++) {
            minDiff = min(minDiff, minLeftSum[i] - maxRightSum[i + 1]);
        }

        return minDiff;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
