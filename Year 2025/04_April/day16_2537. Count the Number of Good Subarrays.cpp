// Problem Link -> https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        long long goodSubarrays = 0;

        unordered_map<int, int> frequencyMap;

        long long currentPairs = 0;

        while(right < n) {
            currentPairs += frequencyMap[nums[right]];
            frequencyMap[nums[right]]++;

            while(currentPairs >= k) {
                goodSubarrays += (n - right);
                frequencyMap[nums[left]]--;
                currentPairs -= frequencyMap[nums[left]];
                left++;
            }

            right++;
        }

        return goodSubarrays;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
