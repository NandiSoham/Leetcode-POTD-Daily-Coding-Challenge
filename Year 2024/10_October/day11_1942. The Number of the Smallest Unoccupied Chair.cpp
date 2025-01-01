// Problem Link -> https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

class Solution {
public:
    typedef pair<int, int> p;
    priority_queue<p, vector<p>, greater<p>> pq;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        set<int> chairNum; 
        
        int lastChair = 0;
        
        for(vector<int> &time : times) {
            int arrival  = time[0];
            int depart   = time[1];
            int currSeat = -1;
 
            while(!pq.empty() && pq.top().first <= arrival) {
                chairNum.insert(pq.top().second); 
                pq.pop();
            }

            if(chairNum.empty()) {
                currSeat = lastChair;
                lastChair++;
            } else {
                currSeat = *(chairNum.begin());  
                chairNum.erase(currSeat); 
            }
            pq.push({depart, currSeat});
            if(arrival == targetArrivalTime)
                return currSeat;
        }
        
        return -1;
    }
};


