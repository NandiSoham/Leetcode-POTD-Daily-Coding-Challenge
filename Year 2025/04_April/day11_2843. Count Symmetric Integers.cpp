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


// Time Complexity -> O(high-low+1) * n [n = number of digits]
// Space Complexity -> O(n)

// =============================================================================


// ================================= Approach - 2 ==============================

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int symmetryCount = 0;

        for(int currNum = low; currNum <= high; currNum++){
            if(currNum >= 10 && currNum <= 99 && currNum % 11 == 0){
                symmetryCount++;
            } else if(currNum >= 1000 && currNum <= 9999){
                int digit1 = currNum / 1000;
                int digit2 = (currNum / 100) % 10;
                int digit3 = (currNum / 10) % 10;
                int digit4 = (currNum / 1) % 10;

                if(digit1 + digit2 == digit3 + digit4) {
                    symmetryCount++;
                }
            }
        }

        return symmetryCount;
    }
};


// Time Complexity -> O(high-low+1)
// Space Complexity -> O(1)
