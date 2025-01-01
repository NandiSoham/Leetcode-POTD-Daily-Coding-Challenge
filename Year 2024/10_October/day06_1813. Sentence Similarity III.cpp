// Problem Link -> https://leetcode.com/problems/sentence-similarity-iii/description/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() < sentence2.length()) {
            swap(sentence1, sentence2);
        }

        deque<string> wordsDeque1, wordsDeque2;
        stringstream stream1(sentence1);
        string word;

        while (stream1 >> word) {
            wordsDeque1.push_back(word);
        }

        stringstream stream2(sentence2);

        while (stream2 >> word) {
            wordsDeque2.push_back(word);
        }

        while (!wordsDeque1.empty() && !wordsDeque2.empty() && wordsDeque1.front() == wordsDeque2.front()) {
            wordsDeque1.pop_front();
            wordsDeque2.pop_front();
        }

        while (!wordsDeque1.empty() && !wordsDeque2.empty() && wordsDeque1.back() == wordsDeque2.back()) {
            wordsDeque1.pop_back();
            wordsDeque2.pop_back();
        }

        return wordsDeque2.empty();
    }
};



// Time Complexity -> O(m+n)
// Space Complexity -> O(m+n)
