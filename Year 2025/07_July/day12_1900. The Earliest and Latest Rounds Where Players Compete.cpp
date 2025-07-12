// Problem Link -> https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int playerA = firstPlayer;
        int playerB = secondPlayer;

        if (playerA == n - playerB + 1) {
            return {1, 1};
        }

        if (playerA > n - playerB + 1) {
            int temp = n - playerA + 1;
            playerA = n - playerB + 1;
            playerB = temp;
        }

        int earliest = n;
        int latest = 1;
        int nextRoundSize = (n + 1) / 2;

        if (playerB <= nextRoundSize) {
            int leftSegment = playerA - 1;
            int middleSegment = playerB - playerA - 1;

            for (int survivorsLeft = 0; survivorsLeft <= leftSegment;
                 survivorsLeft++) {
                for (int survivorsMiddle = 0; survivorsMiddle <= middleSegment;
                     survivorsMiddle++) {
                    int newPosA = survivorsLeft + 1;
                    int newPosB = newPosA + survivorsMiddle + 1;
                    vector<int> result =
                        earliestAndLatest(nextRoundSize, newPosA, newPosB);

                    earliest = min(earliest, result[0] + 1);
                    latest = max(latest, result[1] + 1);
                }
            }
        } else {
            int rightMatches = n - playerB + 1;
            int leftSegment = playerA - 1;
            int middleSegment = rightMatches - playerA - 1;
            int remainingMiddle = playerB - rightMatches - 1;

            for (int survivorsLeft = 0; survivorsLeft <= leftSegment;
                 survivorsLeft++) {
                for (int survivorsMiddle = 0; survivorsMiddle <= middleSegment;
                     survivorsMiddle++) {
                    int newPosA = survivorsLeft + 1;
                    int newPosB = newPosA + survivorsMiddle +
                                  (remainingMiddle + 1) / 2 + 1;

                    vector<int> result =
                        earliestAndLatest(nextRoundSize, newPosA, newPosB);

                    earliest = min(earliest, result[0] + 1);
                    latest = max(latest, result[1] + 1);
                }
            }
        }

        return {earliest, latest};
    }
};
