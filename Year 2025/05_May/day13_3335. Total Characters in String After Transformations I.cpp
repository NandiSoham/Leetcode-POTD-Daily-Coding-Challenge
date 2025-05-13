// Problem Link -> https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        int n = s.length();
        vector<int> charFreq(26, 0);

        for(char &ch : s){
            charFreq[ch - 'a']++;
        }

        for(int round = 1; round <= t; round++){
            vector<int> updatedFreq(26, 0);

            for(int i = 0; i < 26; i++){
                char currChar = i + 'a';
                int freq = charFreq[i];

                if(currChar != 'z'){
                    updatedFreq[(currChar + 1) - 'a'] = (updatedFreq[(currChar + 1) - 'a'] + freq) % mod;
                } else {
                    updatedFreq['a' - 'a'] = (updatedFreq['a' - 'a'] + freq) % mod;
                    updatedFreq['b' - 'a'] = (updatedFreq['b' - 'a'] + freq) % mod;
                }
            }

            charFreq = move(updatedFreq);
        }

        int ansLength = 0;
        for(int i  = 0; i < 26; i++){
            ansLength = (ansLength +charFreq[i]) % mod;
        }

        return ansLength;
    }
};


// Time Complexity -> O(t * 26)
// Space Complexity -> O(1)
