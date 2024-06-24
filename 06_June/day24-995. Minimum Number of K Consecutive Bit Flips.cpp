// Problem Link -> https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

// ------------------------------------------ Approach -1 ---------------------------------------

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int currFlipCount = 0, totalFlips = 0;
        vector<bool> flipIndicator(n, false);

        for(int i = 0; i < n; i++){
            if(i >= k && flipIndicator[i - k] == true){
                currFlipCount--;
            }

            if(currFlipCount % 2 == nums[i]){

                if(i+k > n) return -1;

                currFlipCount++;
                totalFlips++;
                flipIndicator[i] = true;
            }
        }

        return totalFlips;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// ----------------------------------------------------------------------------------------------
