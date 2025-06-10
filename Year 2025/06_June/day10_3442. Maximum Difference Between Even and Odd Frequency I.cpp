// Problem Link -> https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> charFreq(26, 0);

        for(char &ch : s){
            charFreq[ch - 'a']++;
        }

        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;

        for(int i = 0; i < 26; i++){
            if(charFreq[i] == 0) continue;

            if(charFreq[i] % 2 == 0){
                minEvenFreq = min(minEvenFreq, charFreq[i]);
            } else {
                maxOddFreq = max(maxOddFreq, charFreq[i]);
            }
        }

        return maxOddFreq - minEvenFreq;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
