// Problem Link -> https://leetcode.com/problems/zero-array-transformation-i/description/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // First Step: Formation of difference array
        vector<int> diffArr(n, 0);
        for(auto& it : queries){
            int startIdx = it[0];
            int endIdx = it[1];
            int increment = 1;

            diffArr[startIdx] += increment;
            if(endIdx + 1 < n){
                diffArr[endIdx + 1] -= increment;
            }
        }

        //Second Step : Getting cumulative sum
        vector<int> cumSumArr(n, 0);
        int currSum = 0;
        for(int i = 0; i < n; i++){
            currSum += diffArr[i];
            cumSumArr[i] = currSum;
        }

        // Step Three: Check between input array and resultant array (cumSumArr)
        for(int i = 0; i < n; i++){
            if(cumSumArr[i] < nums[i]) return false;
        }

        return true;
    }
};


// Time Complexity -> O(Q + N)
// Space Complexity -> O(N)
