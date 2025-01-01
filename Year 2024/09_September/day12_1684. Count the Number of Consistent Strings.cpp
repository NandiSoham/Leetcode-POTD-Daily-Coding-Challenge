// Problem Link -> https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());

        int consistentStringCount = 0;

        for(string &word : words) {
            bool isConsistent = true;  

            for(char &ch : word) {
                if(!allowedSet.count(ch)) { 
                    isConsistent = false;
                    break; 
                }
            }

            consistentStringCount += isConsistent;
        }

        return consistentStringCount;
    }
};  
