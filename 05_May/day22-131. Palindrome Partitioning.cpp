// Problem Link -> https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> currSubstring;
        vector<vector<string>> ans;
        backtrack(0, s, currSubstring, ans);
        return ans;
    }

    void backtrack(int idx, string& s, vector<string> currSubstring,
                   vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(currSubstring);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrom(s, idx, i)) {
                currSubstring.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, currSubstring, ans);
                currSubstring.pop_back();
            }
        }
    }

    bool isPalindrom(string& s, int startIdx, int endIdx) {
        while (startIdx <= endIdx) {
            if (s[startIdx] != s[endIdx])
                return false;
            startIdx++;
            endIdx--;
        }
        return true;
    }
};



// Time Complexity -> O(2^n)
// Space Complexity -> O(k * x) where k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer
