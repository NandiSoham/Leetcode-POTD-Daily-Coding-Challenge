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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuplesCount = 0;
        unordered_map<int, int> productFrequency;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int prodElement = nums[i] * nums[j]; 
                productFrequency[prodElement]++;

            }
        }

        int totalCount = 0;
        for (auto [prodElement, freq] : productFrequency) {
            tuplesCount += 8 * (freq * (freq - 1))/2;        // nC2 -> (n * (n-1))/2
        }

        return tuplesCount;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

// =========================================================================================
