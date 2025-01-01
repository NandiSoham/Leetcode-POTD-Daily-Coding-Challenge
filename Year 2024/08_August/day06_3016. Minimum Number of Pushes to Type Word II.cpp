// Problem Link -> https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freqMap(26, 0);
        int count = 0;

        for(char &ch : word){
            freqMap[ch - 'a']++;
        }

        sort(freqMap.rbegin(), freqMap.rend());

        for(int i = 0; i < 26; i++){
            int pressNum = (i/8) + 1;
            int freqNum = freqMap[i];
            count += pressNum * freqNum;
        }

        return count;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(1)
