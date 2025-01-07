// Problem link -> https://leetcode.com/problems/string-matching-in-an-array/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};



// Time Complexity -> O(n^2 * m)
// Space Complexity -> O(1)
