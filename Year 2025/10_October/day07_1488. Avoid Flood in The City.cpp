// Problem Link -> https://leetcode.com/problems/avoid-flood-in-the-city/description/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> lastRainDay;  
        set<int> availableDryDays;           
        vector<int> result(n, 1);            

        for (int day = 0; day < n; day++) {
            int lake = rains[day];

            if (lake == 0) {
                availableDryDays.insert(day);
            } else {
                result[day] = -1;

                if (lastRainDay.count(lake)) {
                    auto nextDryDay = availableDryDays.lower_bound(lastRainDay[lake] + 1);

                    if (nextDryDay == availableDryDays.end()) {
                        return {};
                    }

                    result[*nextDryDay] = lake;
                    availableDryDays.erase(nextDryDay);
                }

                lastRainDay[lake] = day;
            }
        }

        return result;
    }
};



// Time Complexity -> O(n log n)
// Space Complexity -> O(1)
