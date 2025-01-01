// Problem Link -> https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;

            if(remainderMap.find(remainder) != remainderMap.end()){
                if(i - remainderMap[remainder] >= 2){
                    return true;
                }
            } else{
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
