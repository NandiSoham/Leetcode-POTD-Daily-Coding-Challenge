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

// ---------------------------------------- Approach - 2 ---------------------------------------

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> profit;
        long long currSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            int xorVal = nums[i] ^ k;
            profit.push_back(xorVal - nums[i]);
        }

        sort(profit.begin(), profit.end(), greater<int>());

        for(int i = 0; i < profit.size() - 1; i += 2){
            long long pairSum = profit[i] + profit[i+1];

            if(pairSum > 0){
                currSum += pairSum;
            }
        }
        return currSum;
    }
};


// Time Complexity -> O(n long)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------
