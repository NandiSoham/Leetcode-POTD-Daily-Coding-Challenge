// Problem Link -> https://leetcode.com/problems/stone-game-ii/description/

class Solution {
public:
    int totalPiles;
    int memo[2][101][101]; 

    int calculateMaxStones(vector<int>& piles, int currentPlayer, int currentIndex, int maxM) {
        if (currentIndex >= totalPiles)
            return 0;

        if (memo[currentPlayer][currentIndex][maxM] != -1)
            return memo[currentPlayer][currentIndex][maxM];

        int bestOutcome = (currentPlayer == 1) ? -1 : INT_MAX;
        int currentStones = 0;

        for (int x = 1; x <= min(2 * maxM, totalPiles - currentIndex); x++) {
            currentStones += piles[currentIndex + x - 1];

            if (currentPlayer == 1) { // Alice's turn
                bestOutcome = max(bestOutcome, currentStones + calculateMaxStones(piles, 0, currentIndex + x, max(maxM, x)));
            } else { // Bob's turn
                bestOutcome = min(bestOutcome, calculateMaxStones(piles, 1, currentIndex + x, max(maxM, x)));
            }
        }

        return memo[currentPlayer][currentIndex][maxM] = bestOutcome;
    }

    int stoneGameII(vector<int>& piles) {
        totalPiles = piles.size();
        memset(memo, -1, sizeof(memo));
        return calculateMaxStones(piles, 1, 0, 1);
    }
};



// Time Complexity -> O(n^3)
// SPace Complexity -> O(n^3)
