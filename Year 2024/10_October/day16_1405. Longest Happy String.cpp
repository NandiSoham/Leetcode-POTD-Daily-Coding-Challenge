// Problem Link -> https://leetcode.com/problems/longest-happy-string/description/

class Solution {
public:
    typedef pair<int, char> CharCountPair;

    string longestDiverseString(int countA, int countB, int countC) {
        priority_queue<CharCountPair, vector<CharCountPair>> maxHeap;

        if (countA > 0) {
            maxHeap.push({countA, 'a'});
        }
        if (countB > 0) {
            maxHeap.push({countB, 'b'});
        }
        if (countC > 0) {
            maxHeap.push({countC, 'c'});
        }

        string result = "";

        while (!maxHeap.empty()) {
            int highestCount = maxHeap.top().first;
            char highestChar = maxHeap.top().second;
            maxHeap.pop();

            if (result.length() >= 2 && result.back() == highestChar &&
                result[result.length() - 2] == highestChar) {
                if (maxHeap.empty()) {
                    break;
                }

                int nextCount = maxHeap.top().first;
                char nextChar = maxHeap.top().second;
                maxHeap.pop();

                result.push_back(nextChar);
                nextCount--;

                if (nextCount > 0) {
                    maxHeap.push({nextCount, nextChar});
                }
                maxHeap.push({highestCount, highestChar});
            } else {
                result.push_back(highestChar);
                highestCount--;

                if (highestCount > 0) {
                    maxHeap.push({highestCount, highestChar});
                }
            }
        }

        return result;
    }
};
