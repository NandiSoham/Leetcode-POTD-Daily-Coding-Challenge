// Problem Link -> https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        int mismatchCount = 0;
        vector<int> mismatchArr;
        int idx = 0;

        while (idx < s1.size()) {
            if (s1[idx] != s2[idx]) {
                mismatchArr.push_back(s1[idx]);
                mismatchArr.push_back(s2[idx]);
                mismatchCount++;
            }

            if (mismatchCount > 2)
                return false;
            idx++;
        }

        if (mismatchArr.size() == 4) {
            return (mismatchArr[0] == mismatchArr[3] and
                    mismatchArr[1] == mismatchArr[2]);
        }
        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
