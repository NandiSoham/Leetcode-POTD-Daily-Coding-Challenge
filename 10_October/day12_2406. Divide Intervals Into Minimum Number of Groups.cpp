// Problem Link -> https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        priority_queue<int, vector<int>, greater<int>> minHeap; 

        for(vector<int>& interval : intervals) {
            int startTime = interval[0];
            int endTime   = interval[1];

            if(!minHeap.empty() && minHeap.top() < startTime) {
                minHeap.pop();
            }
            
            minHeap.push(endTime);
        }

        return minHeap.size();
    }
};



// Time Complexity -> O(nlogn)
// Space Compelxity -> O(n)
