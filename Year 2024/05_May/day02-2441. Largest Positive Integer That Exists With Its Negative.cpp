// Problem Link -> https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            for(int j = i+1; j < nums.size();j++){
                if(nums[j] == - nums[i]){
                    result = max(result, abs(nums[i]));
                }
            }
        }
        return result;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------

// ---------------------------------------- Approach - 2  ---------------------------------------

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int startIdx = 0;
        int endIdx = nums.size() - 1;
        int ans = -1;
        sort(nums.begin(), nums.end());

        while(startIdx < endIdx){
            if(-nums[startIdx] == nums[endIdx]) return nums[endIdx];
            if(-nums[startIdx] < nums[endIdx]) endIdx--;
            else startIdx++;
        }
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------
