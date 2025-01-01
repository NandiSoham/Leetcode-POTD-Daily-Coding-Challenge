// Problem Link -> https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

class Solution {
public:
    int wordLength;
    int targetLength;
    int memo[1001][1001];
    const int mod = 1e9 + 7;

    int countWays(int i, int j, vector<vector<long long>> &freqMap, string &target){
        if(i == targetLength) return 1;
        if(j == wordLength) return 0;

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int notTaken = countWays(i, j + 1, freqMap, target) % mod;
        int taken = (freqMap[target[i] - 'a'][j] * countWays(i + 1, j + 1, freqMap, target)) % mod;

        return memo[i][j] = (taken + notTaken) % mod;
    }

    int numWays(vector<string>& words, string target) {
        targetLength = target.length();
        wordLength = words[0].length();
        vector<vector<long long>> freqMap(26, vector<long long>(wordLength));

        for(int col = 0; col < wordLength; col++){
            for(string &word : words){
                char ch = word[col];
                freqMap[ch - 'a'][col]++;
            }
        }

        memset(memo, -1, sizeof(memo));
        return countWays(0, 0, freqMap, target);
    }
};



// Time Complexity -> O(wordLength * targetLength)
// Space Complexity -> O(wordLength * targetLength)
