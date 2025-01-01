class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        long long perimeter = 0;
        long long prevSideSum    = 0;
        
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < prevSideSum) {
                perimeter = nums[i] + prevSideSum;
            }
            prevSideSum += nums[i];
        }
        
        return perimeter == 0 ? -1 : perimeter;
    }
};


// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
//Problem Link -> https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/
