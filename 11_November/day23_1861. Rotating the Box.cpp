// Problem Link -> https://leetcode.com/problems/rotating-the-box/description/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int numRows = box.size();
        int numCols = box[0].size();
        vector<vector<char>> rotatedBox(numCols, vector<char>(numRows));

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                rotatedBox[col][row] = box[row][col];
            }
        }

        for (vector<char>& row : rotatedBox) {
            reverse(row.begin(), row.end());
        }

        for (int col = 0; col < numRows; col++) {
            int emptySpaceRow = numCols - 1;
            for (int row = numCols - 1; row >= 0; row--) {
                if (rotatedBox[row][col] == '*') {
                    emptySpaceRow = row - 1;
                } else if (rotatedBox[row][col] == '#') {
                    rotatedBox[row][col] = '.';
                    rotatedBox[emptySpaceRow][col] = '#';
                    emptySpaceRow--;
                }
            }
        }

        return rotatedBox;
    }
};



// Time Complexity -> O(col * row)
// Space Complexity -> O(1)
