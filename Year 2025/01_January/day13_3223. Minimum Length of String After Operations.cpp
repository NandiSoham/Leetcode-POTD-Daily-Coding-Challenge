// Problem Link -> https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int deleted = 0;

        for(int i = 0; i < n; i++) {
            
            freq[s[i] - 'a'] += 1;

            if(freq[s[i]-'a'] == 3) {
                freq[s[i] - 'a'] -= 2; 
                deleted += 2; 
            }
        }

        return n - deleted;

    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
