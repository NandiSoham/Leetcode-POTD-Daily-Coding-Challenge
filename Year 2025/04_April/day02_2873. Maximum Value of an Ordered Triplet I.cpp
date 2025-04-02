// Problem Link -> https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/

class Solution {
    #define ll long long
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll maxProduct = 0;
        ll maxDifference = 0;
        ll maxLeftValue = 0;

        for(int i = 0; i < n; ++i){
            maxProduct = max<ll>(maxProduct, 1LL * maxDifference * nums[i]);
            maxDifference = max<ll>(maxDifference, (maxLeftValue - nums[i]));
            maxLeftValue = max<ll>(maxLeftValue, nums[i]);
        }
        
        return maxProduct;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
