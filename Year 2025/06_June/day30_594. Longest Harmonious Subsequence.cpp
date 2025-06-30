// Problem Link -> https://leetcode.com/problems/longest-harmonious-subsequence/description/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for(int &num : nums){
            freqMap[num]++;
        }

        int maxLen = 0;
        for(int &num : nums){
            int mini = num;
            int maxi = num + 1;

            if(freqMap.count(maxi)){
                maxLen = max(maxLen, freqMap[mini] + freqMap[maxi]);
            }
        }

        return maxLen;
    }
};


// Timne Complexity -> O(n)
// Space Complexity -> O(n)
