// Problem Link -> https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        for(int it : nums){
            if(it % 2 == 0) evenCount++;
            else oddCount++;
        }

        int alternateParityLen = 1;
        int prevParity = nums[0] % 2;

        for(int i = 1; i < nums.size(); i++){
            int currParity = nums[i] % 2;

            if(currParity != prevParity){
                alternateParityLen++;
                prevParity = currParity;
            }
        }

        return max({evenCount, oddCount, alternateParityLen});
    }
}; 


// Time Complexity -> O(n)
// SPace Complexity -> O(1)
