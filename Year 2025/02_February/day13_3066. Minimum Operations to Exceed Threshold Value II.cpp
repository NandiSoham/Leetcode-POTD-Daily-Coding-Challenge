// Problem Link -> https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
        int operationCount = 0;

        while(pq.top() < k){
            long smallestNum = pq.top();
            pq.pop();

            long secSmalletNum = pq.top();
            pq.pop();

            pq.push(min(smallestNum, secSmalletNum) * 2 + (smallestNum, secSmalletNum));
            operationCount++;
        }

        return operationCount;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
