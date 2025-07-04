// Problem Link -> https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) {
            return 'a';
        }

        int totalOps = operations.size();
        int opType;
        long long currLen = 1;
        long long adjustedK;

        for (int i = 0; i < totalOps; i++) {
            currLen *= 2;
            if (currLen >= k) {
                opType = operations[i];
                adjustedK = k - currLen / 2;
                break;
            }
        }

        char prevChar = kthCharacter(adjustedK, operations);

        if (opType == 0)
            return prevChar;

        if (prevChar == 'z')
            return 'a';

        return prevChar + 1;
    }
};


// Time Complexity -> O(log(k))
// Space Complexity -> O(log(k))
