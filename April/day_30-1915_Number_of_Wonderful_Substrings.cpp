// Problem Link -> https://leetcode.com/problems/number-of-wonderful-substrings/description/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> mpp;
        int xorSum = 0;
        mpp[0] = 1;
        long long ans = 0;

        for(char &c : word){
            int shiftIdx = c - 'a';
            xorSum ^= (1 << shiftIdx);
            ans += mpp[xorSum];

            for(char ch = 'a'; ch <= 'j'; ch++){
                shiftIdx = ch - 'a';
                long long xorCheck = (xorSum ^(1 << shiftIdx));
                ans += mpp[xorCheck];
            }
            mpp[xorSum]++;
        }
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
