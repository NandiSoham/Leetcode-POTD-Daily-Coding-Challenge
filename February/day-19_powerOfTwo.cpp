//=========================== APPROACH - 1 ===========================================

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int result = n & (n - 1);
        if(result == 0) return true;
        else return false;
    }
};

// Time Complexity -> O(1)
// Space Complexity -> O(1)
// Problem Statement -> https://leetcode.com/problems/power-of-two/description/

// ============================== Approach - 2 ===============================

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (1073741824%n==0);
    }
};
