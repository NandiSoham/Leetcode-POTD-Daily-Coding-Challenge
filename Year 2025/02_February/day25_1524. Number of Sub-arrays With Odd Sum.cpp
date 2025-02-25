// Problem Link -> https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;;
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int currSum = 0;

                for(int k = i; k <= j; k++){
                    currSum += arr[k];
                }

                if(currSum % 2 != 0) count++;
            }
        }

        return count % mod;
    }
};


// Time Complexity ->O(n^3)
// Space Complexity -> O(1)

// =========================================================================================
