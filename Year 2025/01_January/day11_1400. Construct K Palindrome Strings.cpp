// Problem Link -> https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        
        if (n < k) return false;

        if (n == k) return true;

        vector<int> charFrequency(26, 0);
        for (char& ch : s) {
            charFrequency[ch - 'a']++;
        }

        int oddFrequencyCount = 0;
        for (int freq : charFrequency) {
            if (freq % 2 != 0) {
                oddFrequencyCount++;
            }
        }

        return oddFrequencyCount <= k;
    }
};




// Time Complexity -> O(n)
// SPace Complexity -> O(1)
