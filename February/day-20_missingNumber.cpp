//============================= APPROACH - 1 ===================================
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int *hash = new int[n + 1]();

        for (int i = 0; i < n; i++)
            hash[nums[i]]++;

        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

// Time Complexity -> O(n) + O(n) ~ O(2*n)
// Space Complexity -> O(n)
//Problem Link -> https://leetcode.com/problems/missing-number/description/

//=================================================================================

//========================= APPROACH - 2 (Optimal) ================================

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedXor = 0, actualXor = 0;

        for(int i = 0; i < n; i++){
            actualXor = actualXor ^ nums[i];
            expectedXor = expectedXor ^ (i + 1);
        }
        return expectedXor ^ actualXor;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ====================================================================================
