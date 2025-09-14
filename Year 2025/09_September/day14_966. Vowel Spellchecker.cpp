// Problem Link -> https://leetcode.com/problems/vowel-spellchecker/description/

class Solution {
public:
    unordered_set<string> wordBank;               
    unordered_map<string, string> lowerDict;       
    unordered_map<string, string> vowelDict;       
    
    string toLowerCase(const string& s) {
        string out = s;
        for (char& ch : out) ch = tolower(ch);
        return out;
    }

    string maskVowelPattern(const string& s) {
        string out = s;
        for (char& ch : out) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ch = '*';
            }
        }
        return out;
    }

    string resolveQuery(const string& query) {
        if (wordBank.count(query)) return query;

        string low = toLowerCase(query);
        if (lowerDict.find(low) != lowerDict.end()) return lowerDict[low];

        string masked = maskVowelPattern(low);
        if (vowelDict.find(masked) != vowelDict.end()) return vowelDict[masked];

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        wordBank.clear();
        lowerDict.clear();
        vowelDict.clear();

        for (auto& word : wordlist) {
            wordBank.insert(word);

            string low = toLowerCase(word);
            if (!lowerDict.count(low)) lowerDict[low] = word;

            string masked = maskVowelPattern(low);
            if (!vowelDict.count(masked)) vowelDict[masked] = word;
        }

        vector<string> output;
        output.reserve(queries.size());
        for (auto& q : queries) {
            output.push_back(resolveQuery(q));
        }
        return output;
    }
};



// Time Complexity -> O((W + Q) * L)
// Space Complexity -> O(W * L)
