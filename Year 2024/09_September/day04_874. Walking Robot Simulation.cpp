// Problem Link -> https://leetcode.com/problems/walking-robot-simulation/description/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for(auto &it : obstacles){
            string obstacleKey = to_string(it[0]) + '-' + to_string(it[1]);
            obstacleSet.insert(obstacleKey);
        }

        int currentX = 0, currentY = 0;
        int maxDistance = 0;
        pair<int, int> direction = {0, 1};

        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                direction = {direction.second, -direction.first};
            } else if (commands[i] == -2){
                direction = {-direction.second, direction.first};
            } else {
                for(int step = 0; step < commands[i]; step++){
                    int nextX = currentX + direction.first;
                    int nextY = currentY + direction.second;
                    string newPositionKey = to_string(nextX) + '-' + to_string(nextY);

                    if(obstacleSet.find(newPositionKey) != obstacleSet.end()) break;

                    currentX = nextX;
                    currentY = nextY;
                }
            }

            maxDistance = max(maxDistance, currentX * currentX + currentY * currentY);
        }

        return maxDistance;
    }
};


//Time Complexity -> O(m + n * maxValCommand), m = size of obstacles, n = size of commands
//Space Complexity -> O(m)
