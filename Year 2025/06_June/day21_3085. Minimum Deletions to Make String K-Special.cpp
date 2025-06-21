// Problem Link -> https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> charFreq(26, 0);
        
        for (char &currChar : word) {
            charFreq[currChar - 'a']++;
        }
        
        int minDeletionsRequired = word.length();
        
        for (int baseChar = 0; baseChar < 26; baseChar++) {
            
            int deletions = 0;
            
            for (int otherChar = 0; otherChar < 26; otherChar++) {
                if (baseChar == otherChar) continue;
                
                if (charFreq[otherChar] < charFreq[baseChar]) {
                    deletions += charFreq[otherChar];
                } else if (abs(charFreq[otherChar] - charFreq[baseChar]) > k) {
                    deletions += abs(charFreq[otherChar] - charFreq[baseChar] - k);
                }
            }
            
            minDeletionsRequired = min(minDeletionsRequired, deletions);
        }
        return minDeletionsRequired;
    }
};


// Time COmplexity -> O(n)
// SPace Complexity -> O(1)
