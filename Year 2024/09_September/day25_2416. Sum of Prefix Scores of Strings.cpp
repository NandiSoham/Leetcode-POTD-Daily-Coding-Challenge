// Problem Link -> https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

struct TrieNode {
    int prefixCount = 0;
    TrieNode* children[26];
};

class Solution {
public:

    TrieNode* createTrieNode() {
        TrieNode* newNode = new TrieNode();
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->prefixCount = 0;
        return newNode;
    }

    void insertWord(string& word, TrieNode* root) {
        TrieNode* currentNode = root;

        for(char &ch : word) {
            int charIndex = ch - 'a';

            if(!currentNode->children[charIndex]) {
                currentNode->children[charIndex] = createTrieNode();
            }

            currentNode->children[charIndex]->prefixCount += 1;
            currentNode = currentNode->children[charIndex];
        }
    }

    int calculatePrefixScore(string& word, TrieNode* root) {
        TrieNode* currentNode = root;
        int totalScore = 0;

        for(char &ch : word) {
            int charIndex = ch - 'a';
            totalScore += currentNode->children[charIndex]->prefixCount;

            currentNode = currentNode->children[charIndex];
        }

        return totalScore;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int totalWords = words.size();

        TrieNode* root = createTrieNode();
        for(string &word : words) {
            insertWord(word, root);
        }

        vector<int> prefixScores(totalWords);

        for(int i = 0; i < totalWords; i++) {
            prefixScores[i] = calculatePrefixScore(words[i], root);
        }

        return prefixScores;
    }
};



// Time Complexity -> O(n*l), n = number of words, l = average length of each word
// Space Complexity -> O(n*l)
