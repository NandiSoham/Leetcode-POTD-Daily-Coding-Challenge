// Problem Link -> https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

class Solution {
public:
    int setBitCount(long long x) {
        int count = 0;
        while (x > 0) {
            if (x & 1) count++;
            x >>= 1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
        long long t = 0;

        while (true) {
            long long val = (long long)num1 - t * (long long)num2;

            if (val < 0) return -1;

            if (setBitCount(val) <= t && t <= val) {
                return (int)t;
            }

            t++;
        }

        return -1;
    }
};


// Time Complexity -> O((num1 / num2) log (num1)
// Space Complexity -> O(1)
