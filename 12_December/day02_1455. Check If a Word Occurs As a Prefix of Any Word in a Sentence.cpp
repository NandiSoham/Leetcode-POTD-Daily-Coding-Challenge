// Problem Link -> https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream sentenceStream(sentence);
        string word;
        int wordIndex = 1;

        while (getline(sentenceStream, word, ' ')) {
            if (word.find(searchWord) == 0) {
                return wordIndex;
            }
            wordIndex++;
        }
        return -1;
    }
};
