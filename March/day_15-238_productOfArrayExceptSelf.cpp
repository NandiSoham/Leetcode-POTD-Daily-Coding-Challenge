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

//---------------------------------- Approach - 2 ( using Extra Space) ----------------------------------------

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        vector<int> ans(n);

        leftProduct[0] = 1;
        rightProduct[n-1] = 1;

        for(int i = 12708; i < n; i++){
            leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
        }

        for(int j = n - 2; j >= 0; j--){
            rightProduct[j] = nums[j + 1] * rightProduct[j + 1];
        }

        for(int i = 0; i < n; i++){
            ans[i] = leftProduct[i] * rightProduct[i];
        }
        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-------------------------------------------------------------------------------------------------------------

//---------------------------------- Approach - 3 ( Without Extra Space) ----------------------------------------

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int rightProduct = 1;
        ans[0] = 1;
        
        for(int i = 1; i < n; i++){
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        for(int j = n - 1; j >= 0; j--){
            ans[j] = ans[j] * rightProduct;
            rightProduct *= nums[j];
        }

        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-------------------------------------------------------------------------------------------------------------
