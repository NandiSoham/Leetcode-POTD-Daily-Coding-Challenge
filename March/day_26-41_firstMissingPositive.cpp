// Problem Link -> https://leetcode.com/problems/first-missing-positive/description/

// ----------------------------- Approcha -1 -> Using Sorting ----------------------------------

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;

        while(i < n && nums[i] <= 0) i++;

        int missingPositive = 1;

        for(int j = i; j < n; j++){
            if (missingPositive == nums[j])
                missingPositive = missingPositive + 1;
                else if (nums[j] > missingPositive)

                return missingPositive;
        }

        return missingPositive;   
    }
};


// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------------

// ----------------------------- Approcha - 2 -> In place Hashing ------------------------------

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while(i < n) {
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        for(i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }

        return n + 1;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------------
