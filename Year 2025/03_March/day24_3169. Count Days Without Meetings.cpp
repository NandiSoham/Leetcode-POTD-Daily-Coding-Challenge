// Problem Link -> https://leetcode.com/problems/count-days-without-meetings/description/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int nextAvailDay = 1;
        int freeDays = 0;

        for(auto &it : meetings){
            int startDay = it[0];
            int endDay = it[1];

            freeDays += max(0, startDay - nextAvailDay);
            nextAvailDay = max (nextAvailDay, endDay + 1);

            if(nextAvailDay > days) break;
        }

        return freeDays + max(0, days - nextAvailDay + 1);
    }
};


// Time Complexity -> O(n logn)
// Space Complexity -> O(1)
