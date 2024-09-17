// Problem Link -> https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

class Solution {
public:
    vector<string> uncommonFromSentences(string sentence1, string sentence2) {
        unordered_map<string, int> wordCountMap;
        
        stringstream sentenceStream1(sentence1);
        string word = "";

        while(sentenceStream1 >> word) 
            wordCountMap[word]++;
        
        stringstream sentenceStream2(sentence2);

        while(sentenceStream2 >> word)
            wordCountMap[word]++;
        
        vector<string> uncommonWords;

        for(auto &entry : wordCountMap) {
            if(entry.second == 1)
                uncommonWords.push_back(entry.first);
        }
        
        return uncommonWords;
    }
};
