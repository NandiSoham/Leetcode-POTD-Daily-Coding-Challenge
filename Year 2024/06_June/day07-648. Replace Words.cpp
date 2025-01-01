// Problem Link -> https://leetcode.com/problems/replace-words/description/

class Solution {
public:

    string findRootWord(string& word, unordered_set<string>& wordSet){
        for(int len = 1; len <= word.length(); len++){
            string root = word.substr(0, len);

            if(wordSet.find(root) != wordSet.end()){
                return root;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        string word, ans;
        stringstream tokenizer(sentence);

        while(getline(tokenizer, word, ' ')){
            ans += findRootWord(word, wordSet) + " ";
        }
        ans.pop_back();

        return ans;
    }
};



// Time Complexity ->  O(n*l + m*l^2) , [ where, n = number of words in the dictionary, m = the number of words in the sentence, and l = the average length of each word.]
// Space Complexity -> O(n)
