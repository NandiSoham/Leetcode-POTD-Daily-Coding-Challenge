// Problem Link -> https://leetcode.com/problems/continuous-subarrays/description/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int size = nums.size();
        map<int, int> frequencyMap; 
        int left = 0; 
        int right = 0; 
        long long subarrayCount = 0; 

        while (right < size) {
            frequencyMap[nums[right]]++;
            
            while (abs(frequencyMap.rbegin()->first - frequencyMap.begin()->first) > 2) {
                frequencyMap[nums[left]]--;
                if (frequencyMap[nums[left]] == 0) {
                    frequencyMap.erase(nums[left]);
                }
                left++;
            }

            subarrayCount += right - left + 1;
            right++;
        }

        return subarrayCount;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
