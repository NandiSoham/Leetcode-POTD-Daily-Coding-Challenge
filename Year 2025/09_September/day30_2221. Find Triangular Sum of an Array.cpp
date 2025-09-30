// Problem Link -> https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        while (n > 1) {
            vector<int> newNum;

            for (int i = 0; i < n - 1; i++) {
                newNum.push_back((nums[i] + nums[i + 1]) % 10);
            }
            
            nums = move(newNum);
            n--;
        }

        return nums[0];
    }
};


// Time Complexity -> O(n²)
// Space Complexity -> O(n)
