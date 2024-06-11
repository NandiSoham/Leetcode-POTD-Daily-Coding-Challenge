// Problem Link -> https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();      // Get the length of the strings
        int currCost = 0;        // Initialize current cost to 0
        int maxLen = 0;          // Initialize maximum length of valid substring to 0
        int leftPtr = 0, rightPtr = 0; // Initialize the sliding window pointers
        
        while(rightPtr < n) {    // Traverse the string with the right pointer
            // Add the transformation cost of the current character
            currCost += abs(s[rightPtr] - t[rightPtr]);
            
            // If current cost exceeds maxCost, shrink the window from the left
            while(currCost > maxCost) {
                currCost -= abs(s[leftPtr] - t[leftPtr]);
                leftPtr++;
            }
            
            // Update the maximum length of valid substring
            maxLen = max(maxLen, rightPtr - leftPtr + 1);
            rightPtr++;
        }
        return maxLen;           // Return the maximum length of valid substring
    }
};


// Time Complexity -> O(2*n)
// Space Complexity -> O(1)
