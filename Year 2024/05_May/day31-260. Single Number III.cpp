// Problem Link -> https://leetcode.com/problems/single-number-iii/description/

// ---------------------------------------- Brute Force ----------------------------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int currCount = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    currCount++;
            }
            if(currCount == 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------------------------

// ---------------------------------------- Optimal Approach ----------------------------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long overallXor = 0;
        for(int i = 0; i < nums.size(); i++){
            overallXor = overallXor ^ nums[i];
        }

        long long rightmostBit = (overallXor ^ (overallXor - 1)) & overallXor;
        int firstBucket = 0, secondBucket = 0;

        for(int i = 0; i < nums.size(); i++) {

            if((nums[i] & rightmostBit) != 0)
                firstBucket ^= nums[i];
            
            else
                secondBucket ^= nums[i];
        }
        return {static_cast<int>(firstBucket), static_cast<int>(secondBucket)};
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------------------------
