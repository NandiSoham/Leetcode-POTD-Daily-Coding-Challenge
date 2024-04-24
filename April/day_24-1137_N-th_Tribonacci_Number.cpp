// Problem Link -> https://leetcode.com/problems/n-th-tribonacci-number/description/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:
    int tribonacci(int n) {
        int dpArr[38];
        dpArr[0] = 0;
        dpArr[1] = 1;
        dpArr[2] = 1;

        for(int i = 3; i<=37; i++){
            dpArr[i] = dpArr[i - 1] + dpArr[i - 2] + dpArr[i - 3];
        }

        return dpArr[n];
    }
};



// Time Complexity -> O(n) ~ O(1) [ because for loop will execute for 37 turns only, constant number so we can consider as O(1)]
// Space Complexity -> O(n) ~ O(1)

//-----------------------------------------------------------------------------------------------
