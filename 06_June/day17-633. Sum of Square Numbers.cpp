// Problem Link -> https://leetcode.com/problems/sum-of-square-numbers/description/

// ------------------------------------ Approach - 1 --------------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            double b = sqrt(c - a*a);

            if(b == (int)b) {
                return true;
            }

        }

        return false;
    }
};



// Time Complexity -> sqrt(c * log(c))
// Space Complexity -> O(1)
//-----------------------------------------------------------------------------------


// ------------------------------------ Approach - 2 --------------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++){
            int remaining = c - (int)(a*a);

            int b_start = 0, b_end = remaining;
            while(b_start <= b_end){
                long mid = b_start + (b_end - b_start)/2;

                if(mid * mid == remaining) return true;
                else if(mid * mid < remaining) b_start = mid + 1;
                else b_end = mid - 1;
            }
        }

        return false;
    }
};

//-----------------------------------------------------------------------------------

// ------------------------------------ Approach - 3 --------------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);

        while(a <= b) {
            long squareSum = a*a + b*b;

            if(squareSum < c) {
                a++;
            } else if (squareSum > c) {
                b--;
            } else {
                return true;
            }
        }

        return false;
    }
};

//-----------------------------------------------------------------------------------


