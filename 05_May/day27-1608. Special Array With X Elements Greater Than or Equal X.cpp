// Problem Link -> https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

// ---------------------------- Approch - 1 ( Brute Force ) ----------------------------------

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int x = 0; x <= n; x++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] >= x) count++;
            }
            if(count == x) return x;
        }
        return -1;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)
// -------------------------------------------------------------------------------------------

// ---------------------------- Approch - 2 ( Sorting and Binary Search ) ----------------------------------

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int low = 0, high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            for(int i = 0; i < n; i++){
                if(nums[i] >= mid) count++;
            }
            
            if(count == mid) return mid;
            else if(count < mid) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

// -------------------------------------------------------------------------------------------------------------
