// Problem Link -> https://leetcode.com/problems/max-chunks-to-make-sorted/description/

class Solution {
public:
    int maxChunksToSorted(vector<int>& array) {
        int size = array.size();
        int cumulativeSum = 0;
        int expectedSum = 0;
        int chunkCount = 0;

        for (int index = 0; index < size; index++) {
            cumulativeSum += array[index];
            expectedSum += index;

            if (cumulativeSum == expectedSum) {
                chunkCount++;
            }
        }

        return chunkCount;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
