// Problem Link -> https://leetcode.com/problems/two-best-non-overlapping-events/description/

class Solution {
public:
    int n;
    int memo[100001][3];

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int left = 0, right = n - 1, result = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > endTime) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& events, int index, int count) {
        if (count == 2 || index >= n) {
            return 0;
        }

        if (memo[index][count] != -1) {
            return memo[index][count];
        }

        int nextValidEventIndex = binarySearch(events, events[index][1]);
        int take = events[index][2] + solve(events, nextValidEventIndex, count + 1);
        int notTake = solve(events, index + 1, count);

        return memo[index][count] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        memset(memo, -1, sizeof(memo));

        return solve(events, 0, 0);
    }
};



