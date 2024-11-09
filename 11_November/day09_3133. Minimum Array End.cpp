// Problem Link -> https://leetcode.com/problems/minimum-array-end/description/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x; 

        for(int i = 1; i < n; i++) {
            num = (num + 1) | x;
        }

        return num; 
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O(1)
