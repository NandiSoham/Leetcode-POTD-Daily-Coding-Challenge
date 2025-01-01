// Problem Link -> https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin;
        for(int row = 0; row < m; row++){
            int minElement = INT_MAX;
            for(int col = 0; col < n; col++){
                minElement = min(minElement, matrix[row][col]);
            }
            rowMin.push_back(minElement);
        }

        vector<int> colMax;
        for(int col = 0; col < n; col++){
            int maxElement = INT_MIN;
            for(int row = 0; row < m; row++){
                maxElement = max(maxElement, matrix[row][col]);
            }
            colMax.push_back(maxElement);
        }

        vector<int> ans;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]){
                    ans.push_back(matrix[row][col]);
                }
            }
        }

        return ans;
    }
};



// Time Complexity -> O(m*n)
// Space Complexity -> O(m+n)
