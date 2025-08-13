// Problem Link -> https://leetcode.com/problems/power-of-three/description/

// =================================== Approach - 1 ===================================

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        while(n != 1){
            int remainder = n % 3;
            n = n/3;

            if(remainder != 0) return false;
        }

        return true;
    }
};


// Time Complexity -> O(log3 n)
// Space Complexity -> O(1)
// ====================================================================================
