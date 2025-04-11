// Problem Link -> https://leetcode.com/problems/count-symmetric-integers/description/

// ================================= Approach - 1 ==============================

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int symmetryCount = 0;

        for(int i = low; i <= high; i++){
            string str = to_string(i);
            int len = str.length();

            if(len % 2 != 0) continue;

            int leftHalfSum = 0, rigthHalfSum = 0;

            for(int j = 0; j < len/2; j++){
                leftHalfSum += str[j] - '0';
            }

            for(int j = len/2; j < len; j++){
                rigthHalfSum += str[j] - '0';
            }

            if(leftHalfSum == rigthHalfSum) symmetryCount++;
        }

        return symmetryCount;
    }
};


// =============================================================================
