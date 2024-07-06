// Problem Link -> https://leetcode.com/problems/pass-the-pillow/description/

// -------------------------------- Approach - 1 ------------------------------

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1, direction = 1;

        while(time > 0){
            if(idx + direction >= 1 && idx + direction <= n){
                idx += direction;
                time--;
            } else direction *= -1;
        }

        return idx;
    }
};



// Time Complexity -> O(time)
// Space Complexity -> O(1)

// ----------------------------------------------------------------------------
