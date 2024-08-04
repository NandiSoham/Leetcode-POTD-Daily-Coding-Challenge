// Problem Link -> https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        vector<int> tempArr;

        for(int leftPtr = 0; leftPtr < n; leftPtr++){
            int sum = 0;
            for(int rightPtr = leftPtr; rightPtr < n; rightPtr++){
                sum += nums[rightPtr];
                tempArr.push_back(sum);
            }
        }

        sort(tempArr.begin(), tempArr.end());
        int subarraySum = 0;

        for(int i = left - 1; i <= right - 1; i++){
            subarraySum += tempArr[i];
            subarraySum %= mod;
        }

        return subarraySum;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)
