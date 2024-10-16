// Problem Link -> https://leetcode.com/problems/separate-black-and-white-balls/description/

class Solution {
public:
    long long minimumSteps(string binaryString) {
        int length = binaryString.length();
        long long totalSwaps = 0;
        int whiteCount = 0;

        for (int i = length - 1; i >= 0; i--) {
            if (binaryString[i] == '1') {  
                totalSwaps += whiteCount;
            } else { 
                whiteCount++;
            }
        }

        return totalSwaps;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
