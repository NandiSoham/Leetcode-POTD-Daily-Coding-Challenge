// Problem Link -> https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findOptimalSchedule(vector<vector<int>>& events, int currIdx, int k){
        if(currIdx >= n || k == 0) return 0;

        if (dp[currIdx][k] != -1)
            return dp[currIdx][k];

        int startTime = events[currIdx][0];
        int endTime = events[currIdx][1];
        int val = events[currIdx][2];

        int nextEvent = findUpperBound(events, events[currIdx][1]);

        int takeEvent = findOptimalSchedule(events, nextEvent, k - 1) + val;
        int doNotTakeEvent = findOptimalSchedule(events, currIdx + 1, k);

        return dp[currIdx][k] = max(takeEvent, doNotTakeEvent);
    }

    int findUpperBound(vector<vector<int>>& events, int endTime) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > endTime) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return findOptimalSchedule(events, 0, k);
    }
};


// Time Complexity -> O(n.k.log(n)
// Space Complexity -> O(n*k)
