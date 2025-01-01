// Problem Link -> https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int numOperations) {
        long long totalSum = 0;

        priority_queue<int> maxHeap(begin(nums), end(nums)); 

        while (numOperations--) {
            int currentMax = maxHeap.top();
            maxHeap.pop();
            totalSum += currentMax;
            currentMax = ceil(currentMax / 3.0);
            maxHeap.push(currentMax);
        }

        return totalSum;
    }
};


//Time Complexity -> O(n + klogn)
//Space Complexity -> O(k)
