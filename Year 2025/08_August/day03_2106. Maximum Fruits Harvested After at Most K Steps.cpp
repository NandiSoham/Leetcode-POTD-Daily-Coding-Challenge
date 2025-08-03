// Problem Link -> https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> cumulative(n);
        vector<int> positions(n);

        for (int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            cumulative[i] = fruits[i][1] + (i > 0 ? cumulative[i - 1] : 0);
        }

        int maxCollected = 0;

        for (int leftSteps = 0; leftSteps <= k / 2; ++leftSteps) {
            int remainingSteps = k - 2 * leftSteps;

            int leftBound = startPos - leftSteps;
            int rightBound = startPos + remainingSteps;

            int leftIdx = lower_bound(positions.begin(), positions.end(), leftBound) - positions.begin();
            int rightIdx = upper_bound(positions.begin(), positions.end(), rightBound) - positions.begin() - 1;

            if (leftIdx <= rightIdx) {
                int collected = cumulative[rightIdx] - (leftIdx > 0 ? cumulative[leftIdx - 1] : 0);
                maxCollected = max(maxCollected, collected);
            }

            int rightSteps = leftSteps;
            remainingSteps = k - 2 * rightSteps;

            leftBound = startPos - remainingSteps;
            rightBound = startPos + rightSteps;

            leftIdx = lower_bound(positions.begin(), positions.end(), leftBound) - positions.begin();
            rightIdx = upper_bound(positions.begin(), positions.end(), rightBound) - positions.begin() - 1;

            if (leftIdx <= rightIdx) {
                int collected = cumulative[rightIdx] - (leftIdx > 0 ? cumulative[leftIdx - 1] : 0);
                maxCollected = max(maxCollected, collected);
            }
        }

        return maxCollected;
    }
};


// Time Complexity -> O(klogn)
// Space Complexity -> O(n)
