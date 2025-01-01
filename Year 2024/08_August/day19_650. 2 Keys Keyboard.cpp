// Problem Link -> https://leetcode.com/problems/2-keys-keyboard/description/

class Solution {
public:

    int helper(int currentACount, int clipBoardACount, int n ){
        if(currentACount > n) return 10000;
        if(currentACount == n) return 0;

        int operationCopyAllAndPaste = 1 + 1 + helper(currentACount + currentACount, currentACount, n);
        int operationPaste = 1 + helper(currentACount + clipBoardACount, clipBoardACount, n);

        return min(operationCopyAllAndPaste, operationPaste);
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        return 1 + helper(1, 1, n);
    }
};  



// Time Compelxity -> O(n^2)
// Space Complexity -> O(n)
