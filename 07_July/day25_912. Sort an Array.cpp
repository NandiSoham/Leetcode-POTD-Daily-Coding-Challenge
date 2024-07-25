// Problem Link -> https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for(auto &it : nums){
            freqMap[it]++;
        }

        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        int idx = 0;

        for(int i = minNum; i <= maxNum; i++){
            while(freqMap[i] > 0){
                nums[idx] = i;
                idx++;
                freqMap[i]--;
            }
        }

        return nums;
    }
};


// Time Complexity -> O(n+k)
// Space Complexity -> O(n)
