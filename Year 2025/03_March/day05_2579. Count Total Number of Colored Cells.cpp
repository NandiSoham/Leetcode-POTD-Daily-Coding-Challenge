// Problem Link -> https://leetcode.com/problems/count-total-number-of-colored-cells/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    long long coloredCells(int n) {
        int iteration = 1;
        long long cellCount = 1;

        while(iteration <= n){
            cellCount += 4 * (iteration - 1);
            iteration++;
        }

        return cellCount;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (2 * (long long)(n - 1) * n);
    }
};


// Time Complexity -> O(1)
// SPace Complexity -> O(1)

// =========================================================================================
