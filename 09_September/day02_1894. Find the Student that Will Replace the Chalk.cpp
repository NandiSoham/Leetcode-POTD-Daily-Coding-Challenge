// Problem Link -> https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

// ------------------------- Approach - 1 ( TLE issue ) ----------------------

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


// -------------------------- Approach - 2 -------------------------------

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long chalkSum = 0;

        for(int &chalkNeeded : chalk){
            chalkSum += chalkNeeded;
        }

        int remainingChalk = k % chalkSum;
        for(int i = 0; i < n; i++){
            if(remainingChalk < chalk[i]) return i;
            remainingChalk -= chalk[i];
        }

        return -1;
    }
};



// Time Complexity -> O(n)
// Soace Complexity -> O(1)

// -----------------------------------------------------------------------
