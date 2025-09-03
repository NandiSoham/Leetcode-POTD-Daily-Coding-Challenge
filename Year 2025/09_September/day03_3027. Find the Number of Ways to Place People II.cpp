// Problem Link -> https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& coords) {
        int n = coords.size();

        sort(coords.begin(), coords.end(), [](vector<int>& p1, vector<int>& p2) {
            return (p1[0] != p2[0]) ? p1[0] < p2[0] : p1[1] > p2[1];
        });
        
        int pairCount = 0;
        
        for (int i = 0; i < n; ++i) {

            int leftX = coords[i][0];
            int topY  = coords[i][1];
            
            int lowestYSeen = INT_MIN;  
            
            for (int j = i + 1; j < n; ++j) {

                int rightX = coords[j][0];
                int bottomY = coords[j][1];
                
                if (bottomY > topY) continue;
                
                if (bottomY > lowestYSeen) {
                    ++pairCount;
                    lowestYSeen = bottomY;
                }
            }
        }
        
        return pairCount;
    }
};


// Time Complexity -> O(n^2)
// Space complexity -> O(1)
