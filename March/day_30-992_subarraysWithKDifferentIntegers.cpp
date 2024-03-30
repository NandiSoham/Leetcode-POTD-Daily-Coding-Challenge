class Solution {
public:
    int slidingWindowFunc(vector<int>& nums, int k){
        int left = 0, right = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> freq;

        while(right < n){
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowFunc(nums, k) - slidingWindowFunc(nums, k - 1);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/subarrays-with-k-different-integers/
