// Problem Link -> https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueElements(begin(nums), end(nums));

        int totalUnique = uniqueElements.size();

        int left = 0;
        int right = 0;
        int count = 0;

        unordered_map<int, int> freqMap;
        while(right < n) {
            freqMap[nums[right]]++;

            while(freqMap.size() == totalUnique) {
                count += (n - right);

                freqMap[nums[left]]--;
                if(freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }

            right++;
        }

        return count;
    }
};



// Time Complexity - >O(n)
// Space Complexity -> O(n)
