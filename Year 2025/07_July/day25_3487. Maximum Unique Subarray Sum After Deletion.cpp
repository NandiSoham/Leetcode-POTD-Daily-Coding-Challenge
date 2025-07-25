// Problem Link -> https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/

// ================================== Approach - 1 ==================================

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int maxNeg = INT_MIN;
        int sum  = 0;

        for(int &it : nums){
            if(it <= 0){
                maxNeg = max(maxNeg, it);
            } else if(!st.count(it)){
                sum += it;
                st.insert(it);
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};

// ==================================================================================


// ================================== Approach - 2 ==================================

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> arr(101, -1);
        int maxNeg = INT_MIN;
        int sum  = 0;

        for(int &it : nums){
            if(it <= 0){
                maxNeg = max(maxNeg, it);
            } else if(arr[it] == -1){
                sum += it;
                arr[it] = 1;
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};

// ==================================================================================
