// Problem link -> https://leetcode.com/problems/triangle/description/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t(n, 0);  

        t[0] = triangle[0][0];  

        for (int row = 1; row < n; row++) {
            for (int col = row; col >= 0; col--) {
                if (col == 0) {
                    t[col] = t[col] + triangle[row][col];  
                } else if (col == row) {
                    t[col] = t[col - 1] + triangle[row][col];  
                } else {
                    t[col] = min(t[col], t[col - 1]) + triangle[row][col];
                }
            }
        }

        return *min_element(t.begin(), t.end());
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(n)
