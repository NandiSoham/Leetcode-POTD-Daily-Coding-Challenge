// Problem link -> https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;

    int dfs(int r, int c, int curMod, vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r >= rows || c >= cols)
            return 0;

        if (r == rows - 1 && c == cols - 1)
            return ((curMod + grid[r][c]) % k == 0);

        if (memo[r][c][curMod] != -1)
            return memo[r][c][curMod];

        int nextMod = (curMod + grid[r][c]) % k;

        int goDown  = dfs(r + 1, c, nextMod, grid, k);
        int goRight = dfs(r, c + 1, nextMod, grid, k);

        return memo[r][c][curMod] = (goDown + goRight) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        memo.assign(rows, vector<vector<int>>(cols, vector<int>(k, -1)));

        return dfs(0, 0, 0, grid, k);
    }
};


// Time Complexity -> O(m × n × k) 
// Space Complexity -> O(m × n × k)
