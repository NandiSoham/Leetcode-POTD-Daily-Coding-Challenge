// Problem Link -> https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

// ---------------------------------------- Approach - 1 ---------------------------------------

class Solution {
public:

    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll currSum = 0;
        int xorIncreaseCount = 0;
        int minDifference = INT_MAX;

        for(auto it : nums){
            int xorVal = it ^ k;
            if(xorVal > it){
                currSum += xorVal;
                xorIncreaseCount++;
            } else {
                currSum += it;
            }

            minDifference = (long long)(min(minDifference, abs(xorVal - it)));
        }

        if(xorIncreaseCount % 2 == 0) return currSum;

        return currSum - minDifference;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------
