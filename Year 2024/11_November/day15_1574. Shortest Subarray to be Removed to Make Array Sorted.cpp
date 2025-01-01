// Problem Link -> https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int arraySize = arr.size();
        int rightStart = arraySize - 1;
        while (rightStart > 0 && arr[rightStart] >= arr[rightStart - 1]) {
            rightStart--;
        }

        int leftEnd = 0;
        int minRemovals = rightStart; 

        while (leftEnd < rightStart && (leftEnd == 0 || arr[leftEnd] >= arr[leftEnd - 1])) {
            while (rightStart < arraySize && arr[leftEnd] > arr[rightStart]) {
                rightStart++;
            }

            minRemovals = min(minRemovals, rightStart - leftEnd - 1);
            leftEnd++;
        }

        return minRemovals;
    }
};



// Time Compelxity -> O(n)
// Space Complexity -> O(1)
