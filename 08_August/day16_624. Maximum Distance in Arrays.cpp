// Problem Link -> https://leetcode.com/problems/maximum-distance-in-arrays/description/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0].front();
        int globalMax = arrays[0].back();
        int maxDistance = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currentMin = arrays[i].front();
            int currentMax = arrays[i].back();
            
            maxDistance = max({maxDistance, abs(currentMin - globalMax), abs(currentMax - globalMin)});

            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }

        return maxDistance;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
