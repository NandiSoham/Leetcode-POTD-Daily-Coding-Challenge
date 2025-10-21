// Problem Link -> https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        int maxi = *max_element(nums.begin(), nums.end()) + k;
        vector<int> freq(maxi + 1, 0);

        for(int it : nums){
            freq[it]++;
        }

        for(int i = 1; i <= maxi; i++){
            freq[i] += freq[i - 1];
        }

        for(int target = 0; target <= maxi; target++){
            if(freq[target] == 0) continue;  
            int left = max(0, target - k);
            int right = min(maxi, target + k);

            int totalCount = freq[right] - (left > 0 ? freq[left - 1] : 0);
            
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
            
            int conversionRequired = totalCount - targetCount;
            
            int maxFreq = targetCount + min(conversionRequired, numOperations);

            ans = max(ans, maxFreq);
        }

        return ans;
    }
};


// Time Complexity -> O(m + n)
// Space complexity -> O(1  )
