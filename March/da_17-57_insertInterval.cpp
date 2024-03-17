// Problem Link  -> https://leetcode.com/problems/insert-interval/description/

// -------------------------------------- Brute Force Approach --------------------------------------------

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][1] < newInterval[0]) i++;
            else if(intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            } else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
        }

        intervals.push_back(newInterval);
        return intervals;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// -------------------------------------------------------------------------------------------------------------
