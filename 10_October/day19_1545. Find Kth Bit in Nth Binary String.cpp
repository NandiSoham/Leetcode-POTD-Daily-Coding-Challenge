// Problem Link -> https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int length = (1 << n) - 1;  

        if (k < (length + 1) / 2) {
            return findKthBit(n - 1, k);
        } 
        else if (k == (length + 1) / 2) {
            return '1';
        } 
        else {
            char mirroredChar = findKthBit(n - 1, length - k + 1);  
            return (mirroredChar == '0') ? '1' : '0'; 
        }
    }
};



// Time Complexity -> O(logn)
// Space Complexity -> O(logn)
