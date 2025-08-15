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


// ======================================== Approach - 2 ========================================

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if(n == 1) return true;
        if(n % 4 != 0) return false;

        return isPowerOfFour(n/4);
    }
};


// Time Complexity -> O(log₄ n)
// Space Complexity -> O(log₄ n)
// ==============================================================================================


// ======================================== Approach - 3 ========================================

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        double x = (log10(n) / log10(4));

        return x == int(x);
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)
// ==============================================================================================


// ======================================== Approach - 4 ========================================

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        
        if((n & (n-1)) == 0 && (n-1) % 3 == 0){
            return true;
        }
        return false;
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)
// ==============================================================================================
