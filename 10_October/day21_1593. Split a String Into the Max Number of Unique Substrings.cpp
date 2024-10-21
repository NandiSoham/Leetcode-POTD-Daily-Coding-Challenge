// problem Link -> https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

class Solution {
public:
    void solve(string& s, int idx, unordered_set<string>& seen, int currCount, int& maxCount) {
        if (currCount + (s.length() - idx) <= maxCount) {
            return;
        }

        if (idx == s.length()) {
            maxCount = max(maxCount, currCount);
            return;
        }

        for (int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j - idx + 1);

            if (seen.find(sub) == seen.end()) {
                seen.insert(sub);  
                solve(s, j + 1, seen, currCount + 1, maxCount);  
                seen.erase(sub);  
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;  
        int maxCount = 0;
        solve(s, 0, seen, 0, maxCount);  
        return maxCount;
    }
};

