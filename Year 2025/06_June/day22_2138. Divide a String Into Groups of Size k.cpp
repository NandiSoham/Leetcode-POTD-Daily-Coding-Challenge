// Problem Link -> https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ansArr;
        int n = s.length();

        int i = 0;
        while (i < n) {
            int j = (i + k - 1 >= n) ? n - 1 : (i + k - 1);
            string currentChunk = s.substr(i, j - i + 1);

            if (j - i + 1 < k) {
                int remainingLength = k - (j - i + 1);
                currentChunk += string(remainingLength, fill);
            }
            ansArr.push_back(currentChunk);

            i += k;
        }

        return ansArr;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(k)
