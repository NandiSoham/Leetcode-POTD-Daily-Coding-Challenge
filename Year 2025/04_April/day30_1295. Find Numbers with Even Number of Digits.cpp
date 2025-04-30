// Problem Link -> https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int evenCount = 0;

        for(int i = 0; i < n; i++){
            string str = to_string(nums[i]);
            int len = str.length();

            if(len % 2 == 0) evenCount++;
        }

        return evenCount;
        
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(1)
