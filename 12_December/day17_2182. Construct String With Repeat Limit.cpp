// Problem Link -> https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string finalString;
        vector<int> charFreq(26, 0);

        for(char &ch : s){
            charFreq[ch - 'a']++;
        }

        int currentIdx = 25;
        while(currentIdx >= 0){
            if(charFreq[currentIdx] == 0){
                currentIdx--;
                continue;
            }

            char currChar = 'a' + currentIdx;
            int allowedFreq = min(charFreq[currentIdx], repeatLimit);
            finalString.append(allowedFreq, currChar);
            charFreq[currentIdx] -= allowedFreq;

            if(charFreq[currentIdx] > 0){
                int j = currentIdx - 1;
                while(j >= 0 && charFreq[j] == 0){
                    j--;
                }

                if(j < 0) break;

                finalString.push_back('a' + j);
                charFreq[j]--;
            }
        }

        return finalString;
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(26) ~ O(1)
