// Problem Link -> https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};



// Time Complexity -> O(m*n)
// Space COmplexity -> O(1)

// =========================================================================================
