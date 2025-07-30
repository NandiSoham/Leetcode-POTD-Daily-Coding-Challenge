// Problem Link -> https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int currLen = 0;
        int result = 0;

        for(int &it: nums){
            if(it > maxVal){
                maxVal = it;
                currLen = 0; 
                result = 0;
            }

            if(it == maxVal){
                currLen++;
            } else currLen = 0;

            result = max(result, currLen);
        }

        return result;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
