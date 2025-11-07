// Problem link -> https://leetcode.com/problems/maximize-the-minimum-powered-city/description/

class Solution {
public:
    bool canAchievePower(long long targetPower, vector<int> stations, int radius, int extraStations) {
        int n = stations.size();
        long long currPower = 0;

        for (int i = 0; i < radius; i++) {
            currPower += stations[i];
        }

        vector<int> added(n, 0); 

        for (int i = 0; i < n; i++) {
            if (i + radius < n) {
                currPower += stations[i + radius];
            }

            if (i - radius - 1 >= 0) {
                currPower -= (stations[i - radius - 1] + added[i - radius - 1]);
            }

            if (currPower < targetPower) {
                long long need = targetPower - currPower;

                if (extraStations < need) return false;

                extraStations -= need;
                currPower += need;
                added[min(i + radius, n - 1)] += need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int radius, int extraStations) {
        long long left = 0, right = 1e18, best = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (canAchievePower(mid, stations, radius, extraStations)) {
                best = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return best;
    }
};



// Time Complexity -> O(n log m)
// Space Complexity -> O(n)
