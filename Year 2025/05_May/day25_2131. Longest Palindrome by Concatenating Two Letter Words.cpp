// Problem Link -> https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordFreq;

        int palindromeLength = 0;

        for(string &currentWord : words) {
            string reversedWord = currentWord;
            swap(reversedWord[0], reversedWord[1]);

            if(wordFreq[reversedWord] > 0) {
                palindromeLength += 4;
                wordFreq[reversedWord]--;
            } else {
                wordFreq[currentWord]++;
            }
        }

        for(auto &entry : wordFreq) {
            string word = entry.first;
            int frequency = entry.second;

            if(word[0] == word[1] && frequency > 0) {
                palindromeLength += 2;
                break;
            }
        }

        return palindromeLength;
    }
};



// time complexity -> O(n)
// space complexity -> O(n)
