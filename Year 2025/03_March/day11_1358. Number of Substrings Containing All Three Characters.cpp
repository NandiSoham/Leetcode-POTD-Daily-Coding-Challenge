// Problem Link -> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// ======================================= Approach - 1 (TLE) ====================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int subStrCount = 0;

        for(int i = 0; i < n; i++){
            int charPresent[3] = {0};

            for(int j = i; j < n; j++){
                charPresent[s[j] - 'a'] = 1;

                if(charPresent[0] + charPresent[1] + charPresent[2] == 3){
                    subStrCount++;
                }
            }
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(1)

// =========================================================================================
