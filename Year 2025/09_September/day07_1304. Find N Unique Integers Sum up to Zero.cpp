// Problem Link -> https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/

// ======================================= Approach - 1 =======================================

class Solution { 
public: 
    vector<int> sumZero(int n) { 
        vector<int> output(n, 0); 
 
        int val = 1; 
        int idx = 0; 
 
        while (idx + 1 < n) { 
            output[idx] = val; 
            output[idx + 1] = -val; 
 
            idx += 2; 
            val++; 
        } 
 
        return output; 
    } 
};


// Time Complexity ->	O(n)
// Space Complexity ->	O(1)

// ============================================================================================


// ======================================= Approach - 2 =======================================

class Solution { 
public: 
    vector<int> sumZero(int n) { 
        vector<int> ansArr(n);   
 
        int left = 0, right = n - 1; 
        int val = 1; 
 
        while (left < right) { 
            ansArr[left] = val; 
            ansArr[right] = -val; 
 
            val++; 
            left++; 
            right--; 
        } 
 
        return ansArr; 
    } 
};


// Time Complexity ->	O(n)
// Space Complexity ->	O(1)

// ============================================================================================
