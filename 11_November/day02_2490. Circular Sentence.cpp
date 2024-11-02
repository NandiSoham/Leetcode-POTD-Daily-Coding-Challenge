// Problem Link -> https://leetcode.com/problems/circular-sentence/description/

class Solution {
public:
    bool isCircularSentence(const std::string& sentence) {
        int n = sentence.length();
        
        for (int i = 1; i < n - 1; i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        
        return sentence[0] == sentence[n - 1];
    }
};
