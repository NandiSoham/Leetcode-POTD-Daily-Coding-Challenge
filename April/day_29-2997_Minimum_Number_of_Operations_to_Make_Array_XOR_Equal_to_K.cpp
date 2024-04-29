class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        for(int it : nums){
            totalXor ^= it;
        }

        int finalXor = totalXor ^ k;
        return __builtin_popcount(finalXor);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
