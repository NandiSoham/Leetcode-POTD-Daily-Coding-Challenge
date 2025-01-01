// Problem Link -> https://leetcode.com/problems/sliding-puzzle/description/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string initialState = "";
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 3; col++) {
                initialState += to_string(board[row][col]);
            }
        }

        string targetState = "123450";

        queue<string> stateQueue;
        stateQueue.push(initialState);

        unordered_map<int, vector<int>> neighborMap = {
            {0, {1, 3}}, {1, {0, 2, 4}}, {2, {1, 5}}, 
            {3, {0, 4}}, {4, {1, 3, 5}}, {5, {2, 4}}
        };

        unordered_set<string> visitedStates;
        visitedStates.insert(initialState);

        int moves = 0;

        while (!stateQueue.empty()) {
            int levelSize = stateQueue.size();

            for (int i = 0; i < levelSize; i++) {
                string currentState = stateQueue.front();
                stateQueue.pop();

                if (currentState == targetState) {
                    return moves;
                }

                int zeroIndex = currentState.find('0');

                for (int neighborIndex : neighborMap[zeroIndex]) {
                    string nextState = currentState;
                    swap(nextState[zeroIndex], nextState[neighborIndex]);

                    if (visitedStates.find(nextState) == visitedStates.end()) {
                        stateQueue.push(nextState);
                        visitedStates.insert(nextState);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
