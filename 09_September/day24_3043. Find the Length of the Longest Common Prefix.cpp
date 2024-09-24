// Problem Link -> https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for(int value : arr1) {
            while(value > 0 && !prefixes.count(value)) {
                prefixes.insert(value);
                value /= 10;  
            }
        }

        int longestPrefixLength = 0;

        for(int value : arr2) {
            int currentValue = value;
            while(currentValue > 0 && !prefixes.count(currentValue)) {
                currentValue /= 10;  
            }

            if(currentValue > 0) {
                int prefixLength = static_cast<int>(log10(currentValue)) + 1;
                longestPrefixLength = max(longestPrefixLength, prefixLength);
            }
        }

        return longestPrefixLength;
    }
};
