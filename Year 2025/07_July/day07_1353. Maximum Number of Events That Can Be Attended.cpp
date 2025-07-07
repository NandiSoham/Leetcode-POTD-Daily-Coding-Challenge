// Problem Link -> https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int n = events.size();
        int currDay = events[0][0];
        int idx = 0, count = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        while(!minHeap.empty() || idx < n){

            // if no events in heap, jump to next event's start day
            if (minHeap.empty()) {
                currDay = events[idx][0];
            }

            // add all events starting on this day
            while(idx < n && events[idx][0] == currDay){
                minHeap.push(events[idx][1]);
                idx++;
            }

            // attend the event that ends earliest
            if(!minHeap.empty()){
                minHeap.pop();
                count++;
            }
            currDay++;

            // remove all expired events (end day < current day)
            while (!minHeap.empty() && minHeap.top() < currDay) {
                minHeap.pop();
            }
        }
        
        return count;       
    }
};



// Time Complexity -> O(n logn)
// SPace Complexity -> O(n)
