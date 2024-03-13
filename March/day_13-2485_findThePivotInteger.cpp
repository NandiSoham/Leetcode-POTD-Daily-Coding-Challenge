// Problem Link -> https://leetcode.com/problems/find-the-pivot-integer/

// ------------------------------ APPROACH - 1 ----------------------------------------------------------

class Solution {
public:
    int pivotInteger(int n) {
        for(int pivot = 1; pivot <= n; pivot++){
            int leftSum = 0, rightSum = 0;

            for(int j = 1; j <= pivot; j++){
                leftSum += j;
            }

            for(int k = pivot; k <= n; k++){
                rightSum += k;
            }

            if(leftSum == rightSum) return pivot;
        }
        return -1;
    }
};


// Time Complexity -> O(n^2)
//Space COmplexity -> O(1)

//-------------------------------------------------------------------------------------------------------

// ------------------------------ APPROACH - 2 -> Little optimization in APPROACH - 1 -------------------

class Solution {
public:
    int pivotInteger(int n) {
        for(int pivot = 1; pivot <= n; pivot++){

            int totalSum = n * (n + 1) / 2;
            int leftSum = pivot * (pivot + 1) / 2; 
            int rightSum = (totalSum - leftSum) + pivot;

            if(leftSum == rightSum) return pivot;
        }
        return -1;
    }
};


// Time Complexity -> O(n)
// Space COmplexity -> O(1)

//-------------------------------------------------------------------------------------------------------

// ---------------------------------------- APPROACH - 3 (2 pointers) ------------------------------------------------

class Solution {
public:
    int pivotInteger(int n) {
        int leftVal = 0, rightVal = n;
        int leftSum = leftVal, rightSum = rightVal;

        if(n == 1) return n;

        while(leftVal < rightVal){
            if(leftSum < rightSum){
                leftVal++;
                leftSum += leftVal;
            } else {
                rightVal--;
                rightSum += rightVal;
            }

            if(leftSum == rightSum && leftVal + 1 == rightVal - 1) return leftVal + 1;
        }
        return -1;
    }
};


// Time Complexity -> O(n)
// Sapce Complexity -> O(1)

//-------------------------------------------------------------------------------------------------------

// ---------------------------------------- APPROACH - 4 ( Maths) ---------------------------------------

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int pivot = sqrt(totalSum);

        if(pivot * pivot == totalSum) return pivot;
        return -1;
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)

//-------------------------------------------------------------------------------------------------------

// ---------------------------------------- APPROACH - 5 ( Binary Search ) ------------------------------

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int leftVal = 0, rightVal = n;

        while(leftVal <= rightVal){
            int midPivot = leftVal + (rightVal - leftVal) / 2;

            if(midPivot * midPivot == totalSum) return midPivot;
            else if(midPivot * midPivot < totalSum) leftVal = midPivot + 1;
            else rightVal = midPivot - 1;
        }
        return -1;
    }
};


// Time Complexity -> O( log n)
// Space Complexity -> O(1)

//-------------------------------------------------------------------------------------------------------

