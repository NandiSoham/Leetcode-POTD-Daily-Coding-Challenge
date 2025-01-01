// Problem Link -> https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, right = 0;
        int currWindowOnes = 0;
        int maxOnesCount = 0;

        while(right < 2*n){
            if(nums[right % n] == 1) currWindowOnes++;

            if(right - left + 1 > totalOnes){
                currWindowOnes -= nums[left % n];
                left++;
            }

            maxOnesCount = max(currWindowOnes, maxOnesCount);
            right++;
        }

        return totalOnes - maxOnesCount;
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O(1)
