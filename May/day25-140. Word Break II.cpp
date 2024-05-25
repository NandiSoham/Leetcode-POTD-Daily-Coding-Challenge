// Problem Link -> https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        string currSentence = "";
        vector<string> ans;
        solve(0, currSentence, s, st, ans);
        return ans;
    }

    void solve(int idx, string& currSentence, string& s, unordered_set<string>& st, vector<string>& ans) {
        if (idx >= s.length()) {
            ans.push_back(currSentence);
            return;
        }

        for (int j = idx; j < s.length(); j++) {
            string tempWord = s.substr(idx, j - idx + 1);
            if (st.count(tempWord)) {
                string tempSentence = currSentence;

                if (!currSentence.empty()) {
                    currSentence += " ";
                }

                currSentence += tempWord;
                solve(j + 1, currSentence, s, st, ans);
                currSentence = tempSentence;
            }
        }
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(n)
