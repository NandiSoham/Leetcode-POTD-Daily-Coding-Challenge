// Problem link -> https://leetcode.com/problems/neighboring-bitwise-xor/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> originalArr(n);

        originalArr[0] = 0;
        for(int i = 0; i < n - 1; i++){
            originalArr[i + 1] = originalArr[i] ^ derived[i];
        }
        if((originalArr[n - 1] ^ originalArr[0]) == derived[n - 1]){
            return true;
        }


        originalArr[0] = 1;
        for(int i = 0; i < n - 1; i++){
            originalArr[i + 1] = originalArr[i] ^ derived[i];
        }
        if((originalArr[n - 1] ^ originalArr[0]) == derived[n - 1]){
            return true;
        }

        return false;s
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XORnum = 0;

        for(int &it : derived) {
            XORnum  = (XORnum ^ it);
        }

        return XORnum == 0;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// =========================================================================================
