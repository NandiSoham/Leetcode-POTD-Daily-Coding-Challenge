// Problem Link -> https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution {
public:
    int minSwaps(string bracketStr) {
        int imbalanceCount = 0; 
        
        for(char &currentChar : bracketStr) {
            if(currentChar == '[') {      
                imbalanceCount++;
            } 
            else if(imbalanceCount != 0) {
                imbalanceCount--; 
            }
        }
        
        return (imbalanceCount + 1) / 2;
    }
};



// Time Complexity -> O(n)
// Spcae Complexity -> O(1)
