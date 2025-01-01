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

// ------------------------------------------- BETTER APPROACH -----------------------------------

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int tripletCount = 0;
        vector<int> prefixXor(arr.begin(), arr.end());
        prefixXor.insert(prefixXor.begin(), 0);
        
        for(int i = 1; i < prefixXor.size(); i++){
            prefixXor[i] ^= prefixXor[i - 1];
        }

        for(int i = 0; i < prefixXor.size(); i++){
            for(int j = i + 1; j < prefixXor.size(); j++){
                if(prefixXor[j] == prefixXor[i])
                    tripletCount += j - i - 1;
            }
        }

        return tripletCount;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

//--------------------------------------------------------------------------------------------

