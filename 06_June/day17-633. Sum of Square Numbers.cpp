// Problem Link -> https://leetcode.com/problems/sum-of-square-numbers/description/

// ------------------------------------ Approach - 1 --------------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            double b = sqrt(c - a*a);

            if(b == (int)b) {
                return true;
            }

        }

        return false;
    }
};



// Time Complexity -> sqrt(c * log(c))
// Space Complexity -> O(1)
//-----------------------------------------------------------------------------------
