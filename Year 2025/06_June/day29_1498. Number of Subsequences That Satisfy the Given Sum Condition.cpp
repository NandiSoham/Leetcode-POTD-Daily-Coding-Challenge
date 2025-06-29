// Problem Link -> https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();

        sort(begin(nums), end(nums));

        vector<int> powerOfTwo(size);
        powerOfTwo[0] = 1;

        for (int i = 1; i < size; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        int left = 0, right = size - 1;
        int count = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                int range = right - left;
                count = (count % MOD + powerOfTwo[range]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
