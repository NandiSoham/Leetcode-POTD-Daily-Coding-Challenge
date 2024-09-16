// Problem Link -> https://leetcode.com/problems/minimum-time-difference/description/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int totalTimes = timePoints.size();
        vector<int> timeInMinutes(totalTimes);

        for(int i = 0; i < totalTimes; i++) {
            string currentTime = timePoints[i];

            string hourPart = currentTime.substr(0, 2); 
            string minutePart = currentTime.substr(3); 

            int hours = stoi(hourPart);
            int minutes = stoi(minutePart);

            timeInMinutes[i] = hours * 60 + minutes;
        }

        sort(begin(timeInMinutes), end(timeInMinutes));

        int minDifference = INT_MAX;

        for(int i = 1; i < totalTimes; i++) {
            minDifference = min(minDifference, timeInMinutes[i] - timeInMinutes[i - 1]);
        }

        return min(minDifference, (24 * 60 - timeInMinutes[totalTimes - 1]) + timeInMinutes[0]);
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
