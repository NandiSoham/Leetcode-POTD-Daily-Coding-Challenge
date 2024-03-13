// Problem Link -> https://leetcode.com/problems/find-the-pivot-integer/

class Solution {
public:
    int pivotInteger(int n) {
        int leftVal = 0, rightVal = n;
        int leftSum = leftVal, rightSum = rightVal;

        if(n == 1) return n;

        while(leftVal < rightVal){
            if(leftSum < rightSum){
                leftVal++;
                leftSum += leftVal;
            } else {
                rightVal--;
                rightSum += rightVal;
            }

            if(leftSum == rightSum && leftVal + 1 == rightVal - 1) return leftVal + 1;
        }
        return -1;
    }
};


// Time Complexity -> O(n)
// Sapce Complexity -> O(1)
