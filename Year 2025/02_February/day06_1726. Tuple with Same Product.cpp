// Problem Link -> https://leetcode.com/problems/tuple-with-same-product/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuplesCount = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                int prodElement = nums[i] * nums[j];
                unordered_set<int> st;

                for(int k = i + 1; k < j; k++){
                    if(prodElement % nums[k] == 0){
                        int dVal = prodElement / nums[k];

                        if(st.count(dVal)) tuplesCount++;

                        st.insert(nums[k]);
                    }
                }
            }
        }

        return tuplesCount * 8;
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(n)

// =========================================================================================
