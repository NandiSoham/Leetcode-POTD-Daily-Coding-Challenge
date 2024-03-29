// Problem Link -> https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

//----------------------------------- Approach - 1 -> (sliding window with nested loop) -----------------------------

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int left = 0, right = 0;
        int ansLength = 0;

        while(right < n){
            mpp[nums[right]]++;

            while(mpp[nums[right]] > k && left < right){
                mpp[nums[left]]--;
                left++;
            }
            ansLength = max(ansLength, right - left + 1);
            right++;
        }
        return ansLength;
    }
};


// Time COmplexity -> O(n)
// Space Complexity -> O(n)

//-------------------------------------------------------------------------------------------------------------------

//--------------------------------- Approach - 1 -> (sliding window without nested loop) -----------------------------

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int left = 0, right = 0;
        int ansLength = 0;
        int culprit = 0;

        while(right < n){
            mpp[nums[right]]++;
            if(mpp[nums[right]] == k+1) culprit++;

            if(culprit > 0){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == k) culprit--;
                left++;
            }
            if(culprit == 0){
                ansLength = max(ansLength, right - left + 1);   
            }
            right++;
        }
        return ansLength;
    }
};


// Time COmplexity -> O(n)
// Space Complexity -> O(n)

//-------------------------------------------------------------------------------------------------------------------
