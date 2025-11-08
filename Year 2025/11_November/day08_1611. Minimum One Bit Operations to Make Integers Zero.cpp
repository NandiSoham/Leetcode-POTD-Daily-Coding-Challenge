// Problem Link -> https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int mask = n;

        while (mask) {
            mask >>= 1;
            n ^= mask;
        }

        return n;
    }
};

// Time Complexity ->	O(log n)
// Space Complexity ->	O(1)
