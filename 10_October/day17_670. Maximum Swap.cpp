// Problem Link -> https://leetcode.com/problems/maximum-swap/description/

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int length = numStr.length();

        vector<int> lastPosition(10, -1);

        for (int i = 0; i < length; i++) {
            int digit = numStr[i] - '0';  
            lastPosition[digit] = i;      
        }

        for (int i = 0; i < length; i++) {
            int currentDigit = numStr[i] - '0'; 

            for (int largerDigit = 9; largerDigit > currentDigit; largerDigit--) {
                if (lastPosition[largerDigit] > i) {  
                    swap(numStr[i], numStr[lastPosition[largerDigit]]);
                    return stoi(numStr);  
                }
            }
        }

        return num;  
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
