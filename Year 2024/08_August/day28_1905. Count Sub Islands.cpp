// Problem Link -> https://leetcode.com/problems/count-sub-islands/description/

class Solution {
public:

    bool checkIfSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        if(row < 0 || row >= grid1.size() || col < 0 || col >= grid1[0].size()){
            return true;
        }

        if(grid2[row][col] != 1) return true;
        grid2[row][col] = -1;

        bool result = (grid1[row][col] == 1);

        result = result & checkIfSubIsland(grid1, grid2, row + 1, col);
        result = result & checkIfSubIsland(grid1, grid2, row - 1, col);
        result = result & checkIfSubIsland(grid1, grid2, row, col + 1);
        result = result & checkIfSubIsland(grid1, grid2, row, col - 1);

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslandsCount = 0;
        int numRows  = grid1.size();
        int numCols = grid1[0].size();

        for(int row = 0; row < numRows; row++){
            for(int col = 0; col < numCols; col++){
                if(grid2[row][col] == 1 && checkIfSubIsland(grid1, grid2, row, col)){
                    subIslandsCount++;
                }
            }
        }

        return subIslandsCount;
    }
};



// Time Complexity -> O(m * n)
// Space Complexity -> O(1)
