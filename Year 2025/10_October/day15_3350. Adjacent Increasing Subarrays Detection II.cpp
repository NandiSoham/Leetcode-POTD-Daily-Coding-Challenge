// Problem  link -> https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        int K = 0;

        for (int i = 1; i < n; i++) {
            if (nums [i] > nums[i-1]) {
                currRun++;
            } else { 
                prevRun = currRun;
                currRun = 1;
            }

            K = max(K, currRun/2);
            K = max(K, min(prevRun, currRun));
        }

        return K;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
