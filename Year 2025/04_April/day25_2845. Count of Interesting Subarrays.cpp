// Problem Link -> https://leetcode.com/problems/count-of-interesting-subarrays/

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        unordered_map<int, long long> remainderFreq; 
        long long prefixCount = 0; 

        long long totalSubarrays = 0;

        remainderFreq[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo  == k)
                prefixCount += 1;

            int currRemainder = prefixCount % modulo ;
            int targetRemainder = (currRemainder - k + modulo ) % modulo ;

            totalSubarrays += remainderFreq[targetRemainder];
            remainderFreq[currRemainder]++;
        }

        return totalSubarrays;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
