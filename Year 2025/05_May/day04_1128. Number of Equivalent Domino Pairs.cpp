// Problem Link -> https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> pairCounts(100);

        int totalPairs = 0;

        for(auto &it : dominoes) {
            if(it[0] > it[1]) {
                swap(it[0], it[1]);
            }

            int key = it[0]*10 + it[1];

            totalPairs += pairCounts[key];

            pairCounts[key]++;
        }

        return totalPairs;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
