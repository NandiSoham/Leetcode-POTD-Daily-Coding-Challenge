// Problem Link -> https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool checkPowersOfThree(int n) {
        return isSumOfPowersOfThree(n, 0);
    }

    int isSumOfPowersOfThree (int n, int exponent){
        if(n == 0) return true;

        if(pow (3, exponent) > n) return false;

        bool includePower = isSumOfPowersOfThree(n - pow (3, exponent), exponent + 1);
        bool excludePower = isSumOfPowersOfThree(n, exponent + 1);

        return includePower || excludePower;
    }
};


// Time Complexity -> O(2 ^ (log3(n)))
// SPace Complexity -> O(log3(n))

// =========================================================================================
