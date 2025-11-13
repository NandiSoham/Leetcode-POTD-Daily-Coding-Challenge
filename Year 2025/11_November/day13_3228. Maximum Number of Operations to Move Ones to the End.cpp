// Problem link -> https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        int seenCount = 0;

        while(i < n) {
            if(s[i] == '0') {
                ans += seenCount;
                while(i < n && s[i] == '0') 
                    i++;
            } else {
                seenCount++;
                i++;
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
