// Problem Link -> https://leetcode.com/problems/smallest-number-with-all-set-bits/description/

// ==================================== Approach - 1 ====================================

class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;

        while(result < n) {
            result = 2 * result + 1;  
        }

        return result;
    }
};


// Time Complexity -> O(log2(n))
// Space Complexity -> O(1)

// ======================================================================================
