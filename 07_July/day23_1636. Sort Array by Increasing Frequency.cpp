// Problem Link -> https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for(auto &it : nums){
            freqMap[it]++;
        }

        auto lambda = [&](int &num1, int &num2){
            if(freqMap[num1] == freqMap[num2]){
                return num1 > num2;
            }
            return freqMap[num1] < freqMap[num2];
        };

        sort(nums.begin(), nums.end(), lambda);

        return nums;
    }
};



// Time Complexity -> O(n)
// Space Complexity ->O(n)
