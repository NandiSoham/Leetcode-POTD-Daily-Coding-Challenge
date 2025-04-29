// Problem link -> https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        long long ans = 0;

        int maxElement = *max_element(nums.begin(), nums.end());
        int countMaxElement = 0;

        while(right < n){
            if(nums[right] == maxElement) countMaxElement++;

            while(countMaxElement >= k){
                ans += n - right;

                if(nums[left] == maxElement) countMaxElement--;
                left++;
            }
            right++;
        }
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
