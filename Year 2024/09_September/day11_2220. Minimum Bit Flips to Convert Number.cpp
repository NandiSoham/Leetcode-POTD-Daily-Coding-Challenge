// Problem link -> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// -------------------------------- Approach - 1 ---------------------------------

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        while(start > 0 || goal > 0) {
            if((start & 1) != (goal & 1)) {
                count++;
            }
            start = (start >> 1);
            goal  = (goal >> 1);
        }

        return count;
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------


// -------------------------------- Approach - 2 ---------------------------------

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int flipCount = 0;  

        while (xorResult) {
            flipCount += (xorResult & 1); 
            xorResult >>= 1;      
        }

        return flipCount;
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------
