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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool isValidPartition(int num, int currentSum, int target) {
        if (num == 0) {
            return currentSum == target;
        }

        return isValidPartition(num / 10, currentSum + num % 10, target) ||
               isValidPartition(num / 100, currentSum + num % 100, target) ||
               isValidPartition(num / 1000, currentSum + num % 1000, target) ||
               isValidPartition(num / 10000, currentSum + num % 10000, target);
    }

    int punishmentNumber(int n) {
        int totalPunishment = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squaredValue = currentNum * currentNum;
            if (isValidPartition(squaredValue, 0, currentNum)) {
                totalPunishment += squaredValue;
            }
        }
        return totalPunishment;
    }
};



// Time Complexity -> O(n * 2^(log10(n)))
// Space Complexity -> O(log10(n))

// =========================================================================================
