// Problem Link -> https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

// ------------------------------------------- BRUTE FORCE -----------------------------------

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int xor_a , xor_b;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            xor_a = 0;
            for(int j = i+1; j < n; j++){
                xor_a ^= arr[j-1];
                xor_b = 0;
                for(int k = j; k < n; k++){
                    xor_b ^= arr[k];
                    if(xor_a == xor_b) count++;
                }
            }
        }
        return count;
    }
};


// Time Complexity -> O(n^3)
// Space Complexity -> O(1)

//--------------------------------------------------------------------------------------------
