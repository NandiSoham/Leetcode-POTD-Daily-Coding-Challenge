// Problem Link ->https://leetcode.com/problems/making-a-large-island/description/

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int exploreIsland(vector<vector<int>>& grid, int x, int y, int& islandId) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != 1)
            return 0;
        
        grid[x][y] = islandId;
        int area = 1;
        
        for (vector<int>& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            area += exploreIsland(grid, newX, newY, islandId);
        }
        
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxIslandSize = 0;
        unordered_map<int, int> islandSizes;
        int islandId = 2;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int size = exploreIsland(grid, i, j, islandId);
                    maxIslandSize = max(maxIslandSize, size);
                    islandSizes[islandId] = size;
                    islandId++;
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    for (vector<int>& dir : directions) {
                        int newX = i + dir[0];
                        int newY = j + dir[1];
                        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != 0)
                            neighboringIslands.insert(grid[newX][newY]);
                    }
                    
                    int potentialSize = 1; 
                    for (const int& island : neighboringIslands) {
                        potentialSize += islandSizes[island];
                    }
                    maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }
        
        return maxIslandSize;
    }
};



// Time Complexity -> O(m * n)
// Space Complexity -> O(m * n)
