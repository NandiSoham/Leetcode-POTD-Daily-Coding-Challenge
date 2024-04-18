// Problem Link ->  https://leetcode.com/problems/island-perimeter/description/

// ---------------------------------------- Approach - 1 (Using DFS) ---------------------------------------

class Solution {
public:
    int m, n;
    int perimeter;

    void findPeriUsingDFS(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 | j >= n || grid[i][j] == 0){
            perimeter++;
            return;
        }

        if(grid[i][j] == -1) return;

        grid[i][j] = -1;

        findPeriUsingDFS(grid, i + 1, j);
        findPeriUsingDFS(grid, i - 1, j);
        findPeriUsingDFS(grid, i, j + 1);
        findPeriUsingDFS(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        perimeter = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    findPeriUsingDFS(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};



// Time Complexity -> O(m X n)
// Space Complexity -> O(1)

// --------------------------------------------------------------------------------------------------------
