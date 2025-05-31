// Problem Link -> https://leetcode.com/problems/snakes-and-ladders/description/

class Solution {
public:
    int boardSize;

    pair<int, int> getCoordinates(int square) {
        int row = boardSize - 1 - (square - 1) / boardSize;
        int col = (square - 1) % boardSize;

        if ((boardSize % 2 == 1 && row % 2 == 1) ||
            (boardSize % 2 == 0 && row % 2 == 0)) {
            col = boardSize - 1 - col;
        }

        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        boardSize = board.size();
        int moveCount = 0;
        queue<int> squareQueue;

        vector<vector<bool>> isVisited(boardSize,
                                       vector<bool>(boardSize, false));
        isVisited[boardSize - 1][0] = true;

        squareQueue.push(1);

        while (!squareQueue.empty()) {
            int currentLevelSize = squareQueue.size();

            while (currentLevelSize--) {
                int currentSquare = squareQueue.front();
                squareQueue.pop();

                if (currentSquare == boardSize * boardSize)
                    return moveCount;

                for (int diceRoll = 1; diceRoll <= 6; diceRoll++) {
                    int nextSquare = currentSquare + diceRoll;
                    if (nextSquare > boardSize * boardSize)
                        break;

                    pair<int, int> nextCoord = getCoordinates(nextSquare);
                    int row = nextCoord.first;
                    int col = nextCoord.second;

                    if (isVisited[row][col])
                        continue;

                    isVisited[row][col] = true;

                    if (board[row][col] == -1)
                        squareQueue.push(nextSquare);
                    else
                        squareQueue.push(board[row][col]);
                }
            }
            moveCount++;
        }

        return -1;
    }
};



