// Problem Link -> https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int intervalCount = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;

        mergedIntervals.push_back(intervals[0]);

        for(int i = 1; i < intervalCount; i++) {
            if(intervals[i][0] < mergedIntervals.back()[1]) { 
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> horizontalCuts;
        vector<vector<int>> verticalCuts;

        for(auto &rectangle : rectangles) {
            int x1 = rectangle[0];
            int y1 = rectangle[1];
            int x2 = rectangle[2];
            int y2 = rectangle[3];

            horizontalCuts.push_back({x1, x2});
            verticalCuts.push_back({y1, y2});
        }

        vector<vector<int>> mergedHorizontal = merge(horizontalCuts);
        if(mergedHorizontal.size() >= 3)
            return true;

        vector<vector<int>> mergedVertical = merge(verticalCuts);

        return mergedVertical.size() >= 3;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
