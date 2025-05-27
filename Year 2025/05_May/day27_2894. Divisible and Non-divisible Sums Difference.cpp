// Problem Link -> https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/

class Solution {
public:
    int differenceOfSums(int n, int m) {

        int totalSum = n * (n + 1) / 2;
        int k = n / m;
        int divisibleSum = m * k * (k + 1) / 2;
        
        return totalSum - 2 * divisibleSum;
    }
};


// time Complexity -> O(1)
// Space Complexitu -> O(1)
