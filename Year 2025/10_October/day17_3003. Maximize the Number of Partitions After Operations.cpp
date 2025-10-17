// Problem Link -> https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description/

class Solution {
public:
    unordered_map<long long, int> memo;
    string str;
    int maxUnique;

    int helper(long long index, long long charMask, bool canModify) {
        long long stateKey = (index << 27) | (charMask << 1) | canModify;

        if (memo.count(stateKey)) {
            return memo[stateKey];
        }

        if (index == str.size()) {
            return 0;  
        }

        int currCharBit = str[index] - 'a';
        int updatedMask = charMask | (1 << currCharBit);
        int distinctCount = __builtin_popcount(updatedMask);

        int maxParts;
        if (distinctCount > maxUnique) {
            maxParts = 1 + helper(index + 1, 1 << currCharBit, canModify);
        } else {
            maxParts = helper(index + 1, updatedMask, canModify);
        }

        if (canModify) {
            for (int ch = 0; ch < 26; ++ch) {
                int modifiedMask = charMask | (1 << ch);
                int modifiedCount = __builtin_popcount(modifiedMask);

                if (modifiedCount > maxUnique) {
                    maxParts = max(maxParts, 1 + helper(index + 1, 1 << ch, false));
                } else {
                    maxParts = max(maxParts, helper(index + 1, modifiedMask, false));
                }
            }
        }

        return memo[stateKey] = maxParts;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        str = s;
        maxUnique = k;
        return helper(0, 0, true) + 1;  
    }
};


// Time Complexity -> O(n × 2^k)
// Space Complexity -> O(n × 2^k)
