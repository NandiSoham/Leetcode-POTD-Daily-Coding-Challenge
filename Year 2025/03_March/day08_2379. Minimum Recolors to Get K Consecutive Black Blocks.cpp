// Problem Link -> https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = INT_MAX;

        for(int i = 0; i <= n - k; i++){
            int currWhiteCount = 0;

            for(int j = i; j - i + 1 <= k; j++){
                if(blocks[j] == 'W'){
                    currWhiteCount++;
                }
            }

            ans = min(ans, currWhiteCount);
        }

        return ans;
    }
};


// Time Complexity -> O(n * k)
// SPace Complexity -> O(1)

// =========================================================================================
