// ----------------------------------- Approach - 1-------------------------------------
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};


//Time Complexity : O(nlogn)
//Space Complexity : O(1)
//------------------------------------------------------------------------------------------

// ------------------------------------- Approach - 2 --------------------------------------

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j  = n - 1, k = n - 1;

        while(k >= 0){
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a > b){
                result[k] = a;
                i++;
            } else{
                result[k] = b;
                j--;
            }
            k--;
        }
        return result;
    }
};




// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/squares-of-a-sorted-array/description/
