// Problem link -> https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution {
public:
    int n;
    void diagonalSort(int startRow, int startCol, vector<vector<int>>& grid, bool ascending){
        vector<int> diagonal;

        for(int i = startRow, j = startCol; i < n && j < n; i++, j++){
            diagonal.push_back(grid[i][j]);
        }

        if(ascending){
            sort(diagonal.begin(), diagonal.end());
        } else {
            sort(diagonal.rbegin(), diagonal.rend());
        }

        int i = startRow, j = startCol;
        for(int &it : diagonal){
            grid[i][j] = it;
            i++,j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        for(int row = 0; row < n; row++){
            diagonalSort(row, 0, grid, false);
        }

        for(int col = 1; col < n; col++){
            diagonalSort(0, col, grid, true);
        }

        return grid;
    }
};


// Time Complexity -> O(n^2 log n)
// Space complexity -> O(n)
