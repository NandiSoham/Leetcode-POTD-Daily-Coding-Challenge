// Problem Link -> https://leetcode.com/problems/largest-perimeter-triangle/description/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));  

        for (int i = n - 3; i >= 0; i--) {
            
            if (nums[i] + nums[i + 1] > nums[i + 2]){
                return nums[i] + nums[i + 1] + nums[i + 2];  
            }
        }

        return 0;  
    }
};

// Time Complexity -> O(n log n)
// Space Complexity -> O(1)
