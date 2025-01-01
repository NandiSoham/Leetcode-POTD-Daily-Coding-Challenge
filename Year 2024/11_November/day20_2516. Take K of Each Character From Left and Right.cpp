// Problem Link -> https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

class Solution {
public:
    int takeCharacters(string inputString, int minDeletions) {
        int length = inputString.length();

        int countA = 0; 
        int countB = 0; 
        int countC = 0;

        for (char &ch : inputString) {
            if (ch == 'a')
                countA++;
            else if (ch == 'b')
                countB++;
            else if (ch == 'c')
                countC++;
        }

        if (countA < minDeletions || countB < minDeletions || countC < minDeletions) {
            return -1; 
        }

        int leftPointer = 0;
        int rightPointer = 0;
        int maxNonDeletedWindowSize = 0;

        while (rightPointer < length) {
            if (inputString[rightPointer] == 'a') {
                countA--;
            } else if (inputString[rightPointer] == 'b') {
                countB--;
            } else if (inputString[rightPointer] == 'c') {
                countC--;
            }

            while (leftPointer <= rightPointer && 
                  (countA < minDeletions || countB < minDeletions || countC < minDeletions)) {
                if (inputString[leftPointer] == 'a') {
                    countA++;
                } else if (inputString[leftPointer] == 'b') {
                    countB++;
                } else if (inputString[leftPointer] == 'c') {
                    countC++;
                }
                leftPointer++;
            }

            maxNonDeletedWindowSize = max(maxNonDeletedWindowSize, rightPointer - leftPointer + 1);
            rightPointer++;
        }

        return length - maxNonDeletedWindowSize; 
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
