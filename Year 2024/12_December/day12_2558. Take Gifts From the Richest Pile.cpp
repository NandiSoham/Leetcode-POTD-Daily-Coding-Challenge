// Problem Link -> https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        long long totalSum = accumulate(begin(gifts), end(gifts), 0LL);

        while (k--) {
            int largestGift = maxHeap.top(); 
            maxHeap.pop();

            int reducedGift = sqrt(largestGift); 
            totalSum -= (largestGift - reducedGift); 
            maxHeap.push(reducedGift); 
        }

        return totalSum;
    }
};



// Time Complexity -> O(n + klogn)
// Space Complexity -> O(n)
