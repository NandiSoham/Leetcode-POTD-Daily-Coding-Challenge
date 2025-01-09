// Problem Link -> https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};



// Time Complexity: O (n ^ m)
// Space Complexity: O (n ^ m)

// =========================================================================================
