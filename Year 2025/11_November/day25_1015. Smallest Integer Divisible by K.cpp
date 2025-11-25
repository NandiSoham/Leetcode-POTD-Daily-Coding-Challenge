// Problem link -> https://leetcode.com/problems/smallest-integer-divisible-by-k/description/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0)
            return -1;

        int currRem = 0;

        for (int i = 1; i <= K; i++) {
            currRem = (currRem * 10 + 1) % K;

            if (currRem == 0) return i;
        }

        return -1; 
    }
};



// Time Complexity -> O(k)
// Space complexity -> O(1)
