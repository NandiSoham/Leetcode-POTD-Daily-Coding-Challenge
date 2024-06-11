class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int countSubarray = 0;
        int productOfSubarray = 1;

        if(k <= 1) return 0;

        while(right < n){
            productOfSubarray *= nums[right];

            while(productOfSubarray >= k){
                productOfSubarray /= nums[left];
                left++;
            }

            countSubarray += (right - left + 1);
            right++;
        }
        return countSubarray;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/subarray-product-less-than-k/
