//Problem Link -> https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string prevTerm = countAndSay(n - 1);
        string currTerm = "";
        
        for(int idx = 0; idx < prevTerm.length(); idx++) {
            int freq = 1;
            char currentChar = prevTerm[idx];
            
            while(idx < prevTerm.length() - 1 && prevTerm[idx] == prevTerm[idx + 1]) {
                freq++;
                idx++;
            }
            
            currTerm += to_string(freq) + string(1, prevTerm[idx]);
        }
        
        return currTerm;
    }
};



// Time Complexity -> O(2 ^ n)
// Space Complexity -> O(2 ^ n)
