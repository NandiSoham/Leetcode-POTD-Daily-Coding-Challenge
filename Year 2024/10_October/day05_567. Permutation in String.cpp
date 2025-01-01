// Problem Link -> https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> s1Freq(26, 0), s2Freq(26, 0);

        if (n > m) return false;

        for (int i = 0; i < n; i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        if (s1Freq == s2Freq) return true;
        
        for (int i = n; i < m; i++) {
            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i - n] - 'a']--;

            if (s1Freq == s2Freq) return true;
        }

        return false;
    }
};




