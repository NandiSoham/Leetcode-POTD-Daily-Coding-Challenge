// Problem Link -> https://leetcode.com/problems/maximum-erasure-value/description/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueElements;
        int left = 0, right = 0;
        int currSum = 0;
        int maxval = 0;

        while(right < n){
            if(!uniqueElements.count(nums[right])){
                currSum += nums[right];
                maxval = max(maxval, currSum);
                uniqueElements.insert(nums[right]);
                right++;
            } else {
                while(uniqueElements.count(nums[right]) && left < n){
                    currSum -= nums[left];
                    uniqueElements.erase(nums[left]);
                    left++;
                }
            }
        }

        return maxval;
    }
};



// time complexity -> O(n)
// SPace Comaplexity -> O(n)
