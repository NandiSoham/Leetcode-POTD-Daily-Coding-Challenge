// Problem Link -> https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero = 0, countOne = 0, countTwo = 0;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0) countZero++;
            else if(nums[i] == 1) countOne++;
            else countTwo++;
        }

        for(int i = 0; i < countZero; i++) nums[i] = 0;
        for(int i = countZero; i < countZero+countOne; i++) nums[i] = 1;
        for(int i  = countZero+countOne; i < nums.size(); i++) nums[i] = 2;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
