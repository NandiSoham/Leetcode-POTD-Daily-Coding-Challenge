// problem Link -> https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        
        freeTime.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - (endTime[endTime.size() - 1]));

        int left = 0, right = 0;
        int currFreeTime = 0;
        int freeTimeSum = 0;
        int n = freeTime.size();

        while(right < n){
            currFreeTime += freeTime[right];

            if(right - left + 1 > k + 1 && left < n) {
                currFreeTime -= freeTime[left];
                left++;
            }

            freeTimeSum = max(freeTimeSum, currFreeTime);
            right++;
        }

        return freeTimeSum;
    }
};


// Time Complexity -> O(n)
// Space complexity -> O(n)
