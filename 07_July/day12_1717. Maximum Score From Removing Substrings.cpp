// Problem Link -> https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

class Solution {
public:
    string removeSubstring(string& s, string& substring) {
        stack<char> strStack;
        for (char& ch : s) {
            if (ch == substring[1] && !strStack.empty() &&
                strStack.top() == substring[0]) {
                strStack.pop();
            } else strStack.push(ch);
        }

        string temp;
        while (!strStack.empty()) {
            temp.push_back(strStack.top());
            strStack.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string greaterValuedStr = (x > y) ? "ab" : "ba";
        string lesserValuedStr = (x < y) ? "ab" : "ba";

        string firstPassTemp = removeSubstring(s, greaterValuedStr);
        int countRemovedPair = (n - firstPassTemp.length()) / 2;
        score += countRemovedPair * max(x, y);

        string secondPassTemp = removeSubstring(firstPassTemp, lesserValuedStr);
        countRemovedPair = (firstPassTemp.length() - secondPassTemp.length()) / 2;
        score += countRemovedPair * min(x, y);

        return score;
    }
};



// Time Complexity-> O(n + n) ~ O(n)
// Space Complexity -> O(n)
