// Problem Link -> https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/description/

class Solution {
public:
    int getState(int freqA, int freqB) {
        int parityA = freqA % 2;
        int parityB = freqB % 2;

        if (parityA == 0 && parityB == 0)
            return 0;
        if (parityA == 0 && parityB == 1)
            return 1;
        if (parityA == 1 && parityB == 0)
            return 2;

        return 3;
    }

    int maxDifference(string s, int k) {
        int len = s.length();

        int maxDiff = INT_MIN;

        for (char chA = '0'; chA <= '4'; chA++) {
            for (char chB = '0'; chB <= '4'; chB++) {
                if (chA == chB) continue;

                vector<int> minDiffState(4, INT_MAX);

                int freqA = 0;
                int freqB = 0;

                int prevFreqA = 0;
                int prevFreqB = 0;

                int left = -1;
                int right = 0;

                while (right < len) {
                    freqA += (s[right] == chA) ? 1 : 0;
                    freqB += (s[right] == chB) ? 1 : 0;

                    while (right - left >= k && freqB - prevFreqB >= 2 &&
                           freqA - prevFreqA >= 1) {
                        int leftState = getState(prevFreqA, prevFreqB);
                        minDiffState[leftState] =
                            min(minDiffState[leftState], prevFreqA - prevFreqB);

                        left++;
                        prevFreqA += (s[left] == chA) ? 1 : 0;
                        prevFreqB += (s[left] == chB) ? 1 : 0;
                    }

                    int rightState = getState(freqA, freqB);
                    int targetState = rightState ^ 2;
                    int minLeftVal = minDiffState[targetState];

                    if (minLeftVal != INT_MAX) {
                        maxDiff = max(maxDiff, (freqA - freqB) - minLeftVal);
                    }

                    right++;
                }
            }
        }

        return maxDiff;
    }
};




// Time Complexity -> O(n)
// SPace COmplexity -> O(1)
