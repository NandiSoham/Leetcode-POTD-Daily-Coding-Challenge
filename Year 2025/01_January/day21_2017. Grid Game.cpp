// Problem link -> https://leetcode.com/problems/grid-game/description/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long remainingSumFirstRow = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long accumulatedSumSecondRow = 0;
        long long minimizedSecondRobotSum = LONG_LONG_MAX;

        for (int currentCol = 0; currentCol < grid[0].size(); currentCol++) { 

            remainingSumFirstRow -= grid[0][currentCol];
            long long bestSecondRobotSum = max(remainingSumFirstRow, accumulatedSumSecondRow);
            minimizedSecondRobotSum = min(minimizedSecondRobotSum, bestSecondRobotSum);

            accumulatedSumSecondRow += grid[1][currentCol];
        }

        return minimizedSecondRobotSum;
    }
};



// Time Complexity -> O(Column Size)
// Space Complexity -> O(1)
