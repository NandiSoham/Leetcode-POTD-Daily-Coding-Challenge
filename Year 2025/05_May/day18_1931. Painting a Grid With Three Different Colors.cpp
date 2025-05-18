// Problem link -> https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

class Solution {
public:
    vector<vector<int>> memo;
    vector<string> validColumnPatterns;
    const int mod = 1e9 + 7;

    void createValidColumns(string currentPattern, int rowsLeft, char lastColor) {
        if (rowsLeft == 0) {
            validColumnPatterns.push_back(currentPattern);
            return;
        }

        for (char color : {'R', 'G', 'B'}) {
            if (color == lastColor)
                continue;
            createValidColumns(currentPattern + color, rowsLeft - 1, color);
        }
    }

    int calculateWaysToColor(int columnsLeft, int prevPatternIdx, int rowCount) {
        if (columnsLeft == 0)
            return 1;
            
        if (memo[columnsLeft][prevPatternIdx] != -1)
            return memo[columnsLeft][prevPatternIdx];

        int totalColorings = 0;
        const string& prevPattern = validColumnPatterns[prevPatternIdx];

        for (int nextColIdx = 0; nextColIdx < validColumnPatterns.size(); nextColIdx++) {
            const string& nextPattern = validColumnPatterns[nextColIdx];
            bool isCompatible = true;

            for (int row = 0; row < rowCount; row++) {
                if (prevPattern[row] == nextPattern[row]) {
                    isCompatible = false;
                    break;
                }
            }

            if (isCompatible) {
                totalColorings = (totalColorings + calculateWaysToColor(columnsLeft - 1, 
                                    nextColIdx, rowCount)) % mod;
            }
        }

        return memo[columnsLeft][prevPatternIdx] = totalColorings;
    }

    int colorTheGrid(int m, int n) {
        validColumnPatterns.clear();
        createValidColumns("", m, '#');

        int totalPatterns = validColumnPatterns.size();
        memo.assign(n, vector<int>(totalPatterns, -1)); 

        int result = 0;
        for (int i = 0; i < totalPatterns; i++) {
            result = (result + calculateWaysToColor(n - 1, i, m)) % mod; 
        }

        return result;
    }
};


