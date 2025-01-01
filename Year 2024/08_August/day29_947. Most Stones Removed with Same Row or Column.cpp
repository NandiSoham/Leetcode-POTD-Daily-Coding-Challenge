// Problem Link -> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution {
public:
    void exploreConnectedStones(vector<vector<int>>& stones, int currentIndex, vector<bool>& visited) {
        visited[currentIndex] = true;

        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i] &&
               (stones[i][0] == stones[currentIndex][0] || stones[i][1] == stones[currentIndex][1])) {
                exploreConnectedStones(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size(), false);
        
        int numOfIslands = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(visited[i])
                continue;
            exploreConnectedStones(stones, i, visited);
            numOfIslands++;
        }
        
        return stones.size() - numOfIslands;
    }
};



// Time Complexity -> O(n ^ 2)
// Space Complexity -> O(n)
