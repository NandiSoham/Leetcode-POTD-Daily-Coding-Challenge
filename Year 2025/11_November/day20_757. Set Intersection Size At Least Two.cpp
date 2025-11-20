// Problem Link -> https://leetcode.com/problems/set-intersection-size-at-least-two/description/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 if (a[1] != b[1]) return a[1] < b[1];
                 return a[0] > b[0];
             });

        int chosen1 = -1;   
        int chosen2 = -1;  
        int picks   = 0;

        for (auto& range : intervals) {
            int left  = range[0];
            int right = range[1];

            if (left <= chosen1) continue;

            if (left > chosen2) {
                picks += 2;
                chosen2 = right;
                chosen1 = right - 1;
            }
            else {
                picks += 1;
                chosen1 = chosen2;
                chosen2 = right;
            }
        }

        return picks;
    }
};


// Time Complexity -> O(n log n)
// Space Complexity -> O(1)
