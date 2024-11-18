// Problem Link -> https://leetcode.com/problems/defuse-the-bomb/description/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int codeSize = code.size();
        vector<int> decryptedArray(codeSize, 0);

        if (k == 0) {
            return decryptedArray;
        }

        int windowStart = -1, windowEnd = -1;
        if (k > 0) {
            windowStart = 1;
            windowEnd = k;
        } else {
            windowStart = codeSize - abs(k);
            windowEnd = codeSize - 1;
        }

        int currentWindowSum = 0;
        for (int currentIndex = windowStart; currentIndex <= windowEnd; currentIndex++) {
            currentWindowSum += code[currentIndex];
        }

        for (int index = 0; index < codeSize; index++) {
            decryptedArray[index] = currentWindowSum;

            currentWindowSum -= code[windowStart % codeSize];
            windowStart++;

            currentWindowSum += code[(windowEnd + 1) % codeSize];
            windowEnd++;
        }

        return decryptedArray;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
