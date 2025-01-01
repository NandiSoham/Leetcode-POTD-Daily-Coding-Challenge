class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int arrowCount = 1;
        sort(points.begin(), points.end());
        vector<int> prev = points[0];

        for(int i = 1; i < n; i++){
            int curStartPoint = points[i][0];
            int curEndPoint = points[i][1];

            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];

            if(curStartPoint > prevEndPoint){ // no  overlap
                prev = points[i];
                arrowCount++;
            } else{ // overlapping case
                prev[0] = max(prevStartPoint, curStartPoint);
                prev[1] = min(prevEndPoint, curEndPoint);
            }
        }
        return arrowCount;
    }
};


// Time Complexity -> O(n logn)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
