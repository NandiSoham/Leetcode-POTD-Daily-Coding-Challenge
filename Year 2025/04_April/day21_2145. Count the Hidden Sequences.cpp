// Problem Link -> https://leetcode.com/problems/count-the-hidden-sequences/description/

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int currVal = 0;
        int minPrefixSum = 0;
        int maxPrefixSum = 0;

        for(int &it : differences) {
            currVal += it;

            minPrefixSum = min(minPrefixSum, currVal);
            maxPrefixSum = max(maxPrefixSum, currVal);

            if((upper - maxPrefixSum) - (lower - minPrefixSum) + 1 <= 0) {
                return 0;
            }
        }

        return (upper - maxPrefixSum) - (lower - minPrefixSum) + 1;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
