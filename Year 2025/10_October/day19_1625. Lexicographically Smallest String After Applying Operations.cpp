// Problem Link -> https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

class Solution {
public:
    void rightRotate(string &str, int b) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + b);
        reverse(str.begin() + b, str.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        string lexSmallest = s;
        unordered_set<string> seen;
        queue<string> q;

        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            string currStr = q.front();
            q.pop();

            if (currStr < lexSmallest)
                lexSmallest = currStr;

            string modified = currStr;
            for (int i = 1; i < modified.size(); i += 2) {++
                int newDigit = (modified[i] - '0' + a) % 10;
                modified[i] = '0' + newDigit;
            }

            if (!seen.count(modified)) {
                seen.insert(modified);
                q.push(modified);
            }

            rightRotate(currStr, b);
            if (!seen.count(currStr)) {
                seen.insert(currStr);
                q.push(currStr);
            }
        }

        return lexSmallest;
    }
};


// time complexity -> O(n^2)
// space complexity -> O(n^2)
