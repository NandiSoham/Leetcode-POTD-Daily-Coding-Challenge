// Problem Link -> https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n+1);
        uglyNumbers[1] = 1;
        int idx2 = 1, idx3 = 1, idx5 = 1;

        for(int i = 2; i <= n ; i++){
            int nextMultipleOf2 = uglyNumbers[idx2] * 2;
            int nextMultipleOf3 = uglyNumbers[idx3] * 3;
            int nextMultipleOf5 = uglyNumbers[idx5] * 5;

            uglyNumbers[i] = min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});

            if(uglyNumbers[i] == nextMultipleOf2) idx2++;
            if(uglyNumbers[i] == nextMultipleOf3) idx3++;
            if(uglyNumbers[i] == nextMultipleOf5) idx5++;
        }

        return uglyNumbers[n];
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
