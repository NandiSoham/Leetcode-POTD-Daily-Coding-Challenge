// Problem Link -> https://leetcode.com/problems/clear-digits/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    string clearDigits(string s) {
        int idx = 0;

        while(idx < s.length()){
            if(isdigit(s[idx])){
                s.erase(idx, 1);

                if(idx - 1 >= 0){
                    s.erase(idx - 1, 1);
                    idx--;
                }
            } else idx++;
        }

        return s;
    }
};



// Time Complexity -> O(n^2)
// Space COmplexity -> O(1)

// =========================================================================================
