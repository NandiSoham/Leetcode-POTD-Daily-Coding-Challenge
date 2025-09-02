// Problem Link -> https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/

// ============================== Approach - 1 ==================================

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int validPairs = 0;

        for (int i = 0; i < n; i++) {

            int leftX = points[i][0];
            int topY = points[i][1];

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int rightX = points[j][0];
                int bottomY = points[j][1];

                if (leftX <= rightX && topY >= bottomY) {
                    bool innerPoint = false;

                    for (int k = 0; k < n; k++) {

                        if (k == i || k == j) continue;

                        int midX = points[k][0];
                        int midY = points[k][1];

                        if (midX >= leftX && midX <= rightX && midY <= topY &&
                            midY >= bottomY) {
                            innerPoint = true;
                            break;
                        }
                    }

                    if (!innerPoint) validPairs++;
                }
            }
        }

        return validPairs;
    }
};


// time Complexity -> O(n^3)
// Space complexity -> O(1)

// ==============================================================================


// ============================== Approach - 2 ==================================

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

// ==============================================================================
