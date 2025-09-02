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
