class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = right & (right -1);
        }
        return right;
    }
};


// Time Complexity -> O(log(n))
// Space Complexity -> O(1)
// Problem Statement -> https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
