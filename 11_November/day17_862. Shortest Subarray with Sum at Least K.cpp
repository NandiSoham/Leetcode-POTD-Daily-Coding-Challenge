// Problem Link -> https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int K) {
        int arraySize = nums.size();
        
        deque<int> indexDeque;
        vector<long long> prefixSum(arraySize, 0);

        int minLength = INT_MAX;
        int currentIndex = 0;

        while (currentIndex < arraySize) {
            if (currentIndex == 0)
                prefixSum[currentIndex] = nums[currentIndex];
            else
                prefixSum[currentIndex] = prefixSum[currentIndex - 1] + nums[currentIndex];
            
            if (prefixSum[currentIndex] >= K) 
                minLength = min(minLength, currentIndex + 1);
            
            while (!indexDeque.empty() && prefixSum[currentIndex] - prefixSum[indexDeque.front()] >= K) {
                minLength = min(minLength, currentIndex - indexDeque.front());
                indexDeque.pop_front();
            }

            while (!indexDeque.empty() && prefixSum[currentIndex] <= prefixSum[indexDeque.back()]) {
                indexDeque.pop_back();
            }

            indexDeque.push_back(currentIndex);
            currentIndex++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
