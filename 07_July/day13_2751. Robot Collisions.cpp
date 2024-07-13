// Problem Link -> https://leetcode.com/problems/robot-collisions/description/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int numRobots = positions.size();
        vector<int> indexOrder(numRobots);

        // Initialize indexOrder with the index positions
        for (int i = 0; i < numRobots; i++) {
            indexOrder[i] = i;
        }

        stack<int> rightMovingRobots;

        auto comparePositions = [&](int i, int j) {
            return positions[i] < positions[j];
        };
        sort(begin(indexOrder), end(indexOrder), comparePositions);

        vector<int> survivingRobots;
        for (int currentIndex : indexOrder) {
            if (directions[currentIndex] == 'R') {
                rightMovingRobots.push(currentIndex);
            } else {
                
                while (!rightMovingRobots.empty() &&
                       healths[currentIndex] > 0) {
                    int rightRobotIndex = rightMovingRobots.top();
                    rightMovingRobots.pop();

                    if (healths[rightRobotIndex] > healths[currentIndex]) {
                        healths[rightRobotIndex] -= 1;
                        healths[currentIndex] = 0;
                        rightMovingRobots.push(rightRobotIndex);
                    } else if (healths[rightRobotIndex] <
                               healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[rightRobotIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[rightRobotIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < numRobots; ++i) {
            if (healths[i] > 0) {
                survivingRobots.push_back(healths[i]);
            }
        }
        return survivingRobots;
    }
};
