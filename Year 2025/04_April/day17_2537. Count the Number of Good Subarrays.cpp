// problem link -> https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] == nums[j] && (i * j) % k == 0){
                    count++;
                }
            }
        }

        return count;
    }
};


// Time Complexity -> O(n ^ 2)
// Space Complexity -> O(1)
