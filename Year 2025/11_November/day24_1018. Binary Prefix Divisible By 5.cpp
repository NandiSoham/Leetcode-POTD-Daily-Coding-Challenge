// Problem link -> http://leetcode.com/problems/binary-prefix-divisible-by-5/description/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ansArr;
        int sum = 0;

        for (int i : nums) {
            sum = sum *2;
            sum = (sum + i) % 5;
            ansArr.push_back(sum == 0?true:false);
        }

        return ansArr;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
