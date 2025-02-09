// Problem Link -> https://leetcode.com/problems/count-number-of-bad-pairs/description/

// ======================================= Approach - 1 (TLE)====================================

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairsCount = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i < j && j - i != nums[j] - nums[i]){
                    badPairsCount++;
                }
            }
        }

        return badPairsCount;
    }
};



// Time Complexity -> O(n^2)
// Space COmplexity -> O(1)

// =========================================================================================
