// Problem Link -> https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class Solution {
public:
    typedef pair<int, int> ElementIndexPair;

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<ElementIndexPair> maxHeap; 
        priority_queue<ElementIndexPair, vector<ElementIndexPair>, greater<ElementIndexPair>> minHeap;  

        int left = 0;  
        int right = 0;  
        int maxLength = 0;  

        while (right < n) {
            maxHeap.push({nums[right], right});  
            minHeap.push({nums[right], right}); 

            while (maxHeap.top().first - minHeap.top().first > limit) {
                left = min(maxHeap.top().second, minHeap.top().second) + 1;

                while (maxHeap.top().second < left) {
                    maxHeap.pop();
                }

                while (minHeap.top().second < left) {
                    minHeap.pop();
                }
            }

            maxLength = max(maxLength, right - left + 1);
            right++; 
        }

        return maxLength; 
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
