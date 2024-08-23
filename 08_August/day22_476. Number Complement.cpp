// Problem Link -> https://leetcode.com/problems/number-complement/description/

// ------------------------------------- Approach - 1 --------------------------------------

class Solution {
public:
    int findComplement(int num) {
        int number_of_bits = (int)(log2(num)) + 1;

        for (int i = 0; i < number_of_bits; i++) {
            num = num ^ (1 << i); 
        }
        return num;
    }
};


// Time Complexity -> O(log2(num))
// Space Complexity -> O(1)

// -----------------------------------------------------------------------------------------


// ------------------------------------- Approach - 2 --------------------------------------

class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num) {
            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};


// Time Complexity -> O(log2(num))
// Space Complexity -> O(1)

// -----------------------------------------------------------------------------------------


// ------------------------------------- Approach - 2 --------------------------------------

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;

        int number_of_bits = (int)(log2(num)) + 1;
        unsigned int mask = (1U << number_of_bits) - 1; 

        return num ^ mask;
    }
};


// Time Complexity -> O(log2(num))
// Space Complexity -> O(1)

// -----------------------------------------------------------------------------------------
