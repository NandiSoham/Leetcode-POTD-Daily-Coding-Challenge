// Problem Link -> https://leetcode.com/problems/binary-subarrays-with-sum/description/

//------------------------- APPROACH - 1 ( Prefix Sum)-------------------------------

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sumCount; 
        int count = 0;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;

            if (currentSum == goal) {
                count++;
            }

            if (sumCount.count(currentSum - goal) > 0) { 
                count += sumCount[currentSum - goal];
            }
            sumCount[currentSum]++;
        }

        return count;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

// --------------------------------------------------------------------------------------

//------------------------- APPROACH - 2 ( Sliding Window )-----------------------------------

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefix_zeros = 0;
        int window_sum = 0;
        int count = 0;
        
        int i = 0, j = 0;
        
        while(j < nums.size()) {
            window_sum += nums[j];
            
            while (i < j && (nums[i] == 0 || window_sum > goal)) {
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                } else {
                    prefix_zeros += 1;
                }
                
                window_sum -= nums[i];
                i++;
            }
            
            if (window_sum == goal) {
                count += 1 + prefix_zeros;
            }
            j++;
        }
        
        return count;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-------------------------------------------------------------------------------------
