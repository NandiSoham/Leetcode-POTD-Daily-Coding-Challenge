// Problem Link -> https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};



// Time Complexity: O (n ^ m)
// Space Complexity: O (n ^ m)

// =========================================================================================


// ======================================= Approach - 1 ====================================

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int prefixCount;

    TrieNode() {
        isEndOfWord = false;
        prefixCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* currentNode = root;
        for (char& ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
            currentNode->prefixCount++;
        }
        currentNode->isEndOfWord = true;
    }

    int searchPrefixCount(string& prefix) {
        TrieNode* currentNode = root;
        for (char& ch : prefix) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return 0;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->prefixCount;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for (string& word : words) {
            trie.insert(word);
        }

        return trie.searchPrefixCount(pref);
    }
};



// Time Complexity: O (n ^ l + m)
// Space Complexity: O (n ^ l)

// =========================================================================================
