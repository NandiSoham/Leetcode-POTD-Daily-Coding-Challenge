// Problem Link -> https://leetcode.com/problems/count-operations-to-obtain-zero/description/

class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)
            return 0;

        if(num1 < num2)
            swap(num1, num2);

        
        return num1/num2 + countOperations(num1%num2, num2);
    }
};


//Time Complexity -> O(log(min(a, b)))
//Space Complexity -> O(1)
