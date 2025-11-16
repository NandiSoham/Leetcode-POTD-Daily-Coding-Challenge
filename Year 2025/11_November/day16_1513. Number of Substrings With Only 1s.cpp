// Problem Link -> https://leetcode.com/problems/number-of-substrings-with-only-1s/description/

class Solution {
public:
    const int mod = 1e9+7;

    int numSub(string s) {
        int ans = 0;
        int count1 = 0;

        for(char ch : s) {
            if (ch == '1') {
                count1++;
                ans = (ans + count1) % mod;
            } else {
                count1 = 0;
            }
        }

        return ans;
    }
};


// time Complexity -> O(n)
// Space Complexity -> O(1)
