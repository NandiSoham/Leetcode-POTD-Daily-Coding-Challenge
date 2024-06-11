class Solution {
public:
    int m, n;

    void findIslandUsingDFS(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 | j >= n || grid[i][j] != '1'){
            return;
        }

        if (grid[i][j] == '#')
            return;

        grid[i][j] = '#';

        findIslandUsingDFS(grid, i + 1, j);
        findIslandUsingDFS(grid, i - 1, j);
        findIslandUsingDFS(grid, i, j + 1);
        findIslandUsingDFS(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    findIslandUsingDFS(grid, i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};



// Time Coplexity -> O(m X n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/number-of-islands/description/
