// Problem Link -> https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

class Solution {
public:
    bool isPrefixAndSuffix(string &candidate, string &word) {
        int length = candidate.length();

        string prefix = word.substr(0, length);
        string suffix = word.substr(word.length() - length, length);
        
        return prefix == candidate && suffix == candidate;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int pairCount = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    pairCount++;
                }
            }
        }
        return pairCount;
    }
};




// Time Complexity -> O(n^2 * l) [n = number of words, l= average word length]
