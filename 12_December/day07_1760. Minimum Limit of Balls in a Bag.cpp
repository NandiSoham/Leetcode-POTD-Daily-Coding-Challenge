// Problem Link -> https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOps, int mid) {
        int totalOps = 0;

        for (int &num : nums) {
            int ops = num / mid;
            if (num % mid == 0) {
                ops -= 1; 
            }
            totalOps += ops;
        }

        return totalOps <= maxOps;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end()); 
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(nums, maxOperations, mid)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};



//Time Complexity -> O(nlog(MAX)), where n = length of nums, MAX = max value in nums
//Space Complexity -> O(1)
