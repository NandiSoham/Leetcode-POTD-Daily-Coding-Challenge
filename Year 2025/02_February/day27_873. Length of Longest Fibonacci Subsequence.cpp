// Problem Link -> https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int, int> valueToIndex;
        
        for (int i = 0; i < size; i++) {
            valueToIndex[arr[i]] = i;
        }
        
        int longestSequence = 0;
        for (int second = 1; second < size; second++) {
            for (int third = second + 1; third < size; third++) {
                int sequenceLength = findSequenceLength(second, third, arr, valueToIndex);
                if (sequenceLength >= 3) {
                    longestSequence = max(longestSequence, sequenceLength);
                }
            }
        }
        return longestSequence >= 3 ? longestSequence : 0;
    }
    
private:
    int findSequenceLength(int second, int third, const vector<int>& arr, const unordered_map<int, int>& valueToIndex) {
        int previousValue = arr[third] - arr[second];
        if (valueToIndex.count(previousValue) && valueToIndex.at(previousValue) < second) {
            int first = valueToIndex.at(previousValue);
            return findSequenceLength(first, second, arr, valueToIndex) + 1;
        }
        return 2;
    }
};



// Time Complexity ->O(n^2)
// Space Complexity -> O(n^2)

// =========================================================================================

// ======================================= Approach - 2 ====================================

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> valueToIndex;
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for (int i = 0; i < n; i++) {
            valueToIndex[arr[i]] = i;
        }

        int longestSequence = 0;
        for (int second = 1; second < n; second++) {
            for (int third = second + 1; third < n; third++) {
                int previousValue = arr[third] - arr[second];
                if (valueToIndex.count(previousValue) &&
                    valueToIndex[previousValue] < second) {
                    int first = valueToIndex[previousValue];
                    dp[second][third] = dp[first][second] + 1;
                }
                longestSequence = max(longestSequence, dp[second][third]);
            }
        }
        return longestSequence >= 3 ? longestSequence : 0;
    }
};


// Time Complexity ->O(n^2)
// Space Complexity -> O(n^2)

// =========================================================================================
