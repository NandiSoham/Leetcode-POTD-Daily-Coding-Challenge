// Problem Link -> https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

class Solution {
public:
    int countPairsWithMaxDistance(vector<int>& numbers, int maxDistance) {
        int pairCount = 0;
        int size = numbers.size();
        int left = 0;
        int right = 1;

        while (right < size) {
            while (numbers[right] - numbers[left] > maxDistance) {
                ++left;
            }
            pairCount += right - left;
            right++;
        }
        return pairCount;
    }

    int smallestDistancePair(vector<int>& numbers, int k) {
        sort(begin(numbers), end(numbers));
        int size = numbers.size();
        int left = 0;
        int right = numbers[size - 1] - numbers[0];
        int result = 0;

        while (left <= right) {
            int midDistance = (left + right) / 2;
            int pairCount = countPairsWithMaxDistance(numbers, midDistance);

            if (pairCount < k) {
                left = midDistance + 1;
            } else {
                result = midDistance; 
                right = midDistance - 1;
            }
        }
        return result;
    }
};



// Time Complexity -> O(nlogn + nlogM), where nlogn is for sorting nums and nlogM is becasue of binary search and sliding window
// Space Complexity -> O(1)
