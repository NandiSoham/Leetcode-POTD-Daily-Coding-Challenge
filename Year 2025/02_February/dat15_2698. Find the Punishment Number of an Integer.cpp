// Problem Link -> https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool isValidPartition(int index, int currentSum, string& squareStr, int target, vector<vector<int>>& memo) {
        if (index == squareStr.length()) {
            return currentSum == target;
        }
        if (currentSum > target) {
            return false;
        }
        if (memo[index][currentSum] != -1) {
            return memo[index][currentSum];
        }

        bool isPossible = false;
        for (int j = index; j < squareStr.length(); j++) {
            int segmentValue = stoi(squareStr.substr(index, j - index + 1));
            isPossible |= isValidPartition(j + 1, currentSum + segmentValue, squareStr, target, memo);
            if (isPossible) {
                return true;
            }
        }
        return memo[index][currentSum] = isPossible;
    }

    int punishmentNumber(int n) {
        int totalPunishment = 0;
        for (int num = 1; num <= n; num++) {
            int squaredValue = num * num;
            string squareStr = to_string(squaredValue);

            vector<vector<int>> memo(squareStr.size(), vector<int>(num + 1, -1));

            if (isValidPartition(0, 0, squareStr, num, memo)) {
                totalPunishment += squaredValue;
            }
        }
        return totalPunishment;
    }
};



// Time Complexity -> O(n * 2^(log10(n^2)))
// Space Complexity -> O(n * log10(n^2))

// =========================================================================================
