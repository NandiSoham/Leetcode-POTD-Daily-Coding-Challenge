// Problem Link -> https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int count = 1;
        int currMinVal = nums[0];

        for(int i = 0; i < n; i++){
            if((nums[i] - currMinVal) > k){
                count++;
                currMinVal = nums[i];
            }
        }

        return count;
    }
};



// Time COmplexity -> O(n logn)
// SPace Complexity -> O(1)
