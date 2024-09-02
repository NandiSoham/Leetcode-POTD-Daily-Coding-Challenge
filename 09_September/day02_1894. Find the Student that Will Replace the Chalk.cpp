// Problem Link -> https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

// ------------------------- Approach ( TLE issue ) ----------------------

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true) {
            for(int i = 0; i < chalk.size(); i++) {
                if(k < chalk[i]) {
                    return i;
                }
            }
        }

        return -1;
    }
};

// -----------------------------------------------------------------------
