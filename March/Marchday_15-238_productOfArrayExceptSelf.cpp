// Problem Link -> https://leetcode.com/problems/product-of-array-except-self/description/

//---------------------------------- Approach - 1 ( using Division) ---------------------------------

// P.S. -> This is a correct approach, but if in question/ interview it's explicitely mentioned not to use division, then avoid this approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 0;
        int product_without_zero = 1;
        int count_zero = 0;
        vector<int> ans(nums.size());

        for(int &it : nums){
            if(it == 0) count_zero++;
            else product_without_zero *= it;
        }

        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];
            if(element != 0){
                if(count_zero > 0) ans[i] = 0;
                else ans[i] = product_without_zero / nums[i];
            }
            else{
                if(count_zero > 1) ans[i] = 0;
                else ans[i] = product_without_zero;
            }
        }
        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-------------------------------------------------------------------------------------------------------------
