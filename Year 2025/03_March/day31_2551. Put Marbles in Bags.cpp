// Problem Link -> https://leetcode.com/problems/put-marbles-in-bags/description/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int pairSize = n - 1;
        vector<int> pairSum(n - 1, 0);

        for(int i = 0; i < pairSize; i++){
            pairSum[i] = weights[i] + weights[i + 1];
        }

        sort(pairSum.begin(), pairSum.end());

        long maxSum = 0, minSum = 0;

        for(int i = 0; i < k - 1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[pairSize - 1 - i];
        }

        return maxSum - minSum;
    }
};


// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
