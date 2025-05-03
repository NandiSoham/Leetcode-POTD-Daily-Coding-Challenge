// Problem Link -> https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/

class Solution {
public:

    int countRotations(vector<int>& tops, vector<int>& bottoms, int targetValue) {
        int dominoCount = tops.size();

        int rotationsToTop = 0;
        int rotationsToBottom = 0;

        for(int i = 0; i < dominoCount; i++) {
            if(tops[i] != targetValue && bottoms[i] != targetValue) {
                return -1;
            } else if(tops[i] != targetValue) {
                rotationsToTop++;
            } else if(bottoms[i] != targetValue) {
                rotationsToBottom++;
            }
        }

        return min(rotationsToTop, rotationsToBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minimumRotations = INT_MAX;

        for(int i = 1; i <= 6; i++) {
            int currentRotations = countRotations(tops, bottoms, i);

            if(currentRotations != -1) {
                minimumRotations = min(minimumRotations, currentRotations);
            }
        }

        return minimumRotations == INT_MAX ? -1 : minimumRotations;
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(1)
