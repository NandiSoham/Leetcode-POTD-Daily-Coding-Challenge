// Problem Link -> https://leetcode.com/problems/power-of-four/description/

// ======================================== Approach - 1 ========================================

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while(n != 1){
            int remainder = n % 4;
            n /= 4;

            if(remainder != 0) return false;
        }

        return true;
    }
};


// Time Complexity -> O(log₄ n)
// Space Complexity -> O(1)
// ==============================================================================================
