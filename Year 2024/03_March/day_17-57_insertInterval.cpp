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

// -------------------------------------- Optimal Approach --------------------------------------------

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;

        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1])
                break;
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);

        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
        
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-------------------------------------------------------------------------------------------------------
