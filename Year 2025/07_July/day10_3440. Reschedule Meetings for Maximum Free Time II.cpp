// Problem Link -> https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        
        freeTime.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - (endTime[endTime.size() - 1]));

        int n = freeTime.size();
        vector<int> maxRightFreeGap(n, 0);
        vector<int> maxLeftFreeGap(n, 0);

        for(int i = n-2; i >= 0; i--) {
            maxRightFreeGap[i] = max(maxRightFreeGap[i+1], freeTime[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFreeGap[i] = max(maxLeftFreeGap[i-1], freeTime[i-1]);
        }

        int maxFreeTime = 0;
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; 

            // case-1 
            if(currEventTime <= max(maxLeftFreeGap[i-1], maxRightFreeGap[i])) {
                maxFreeTime = max(maxFreeTime, freeTime[i-1] + currEventTime + freeTime[i]);
            }

            // case-2 
            maxFreeTime = max(maxFreeTime, freeTime[i-1] + freeTime[i]);
        }

        return maxFreeTime;

    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
