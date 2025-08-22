// Problem Link -> https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int top = rows, bottom = -1;
        int left = cols, right = -1;
        int area = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    top = min(top, r);
                    bottom = max(bottom, r);
                    left = min(left, c);
                    right = max(right, c);
                }
            }
        }

        area = (bottom - top + 1) * (right - left + 1);
        return area;
    }
};


// Time Complexity -> O(m * n)
// Space Complexity -> O(1)
