// Problem Link -> https://leetcode.com/problems/rabbits-in-forest/description/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> ansFreq;
        for (int& it : answers) {
            ansFreq[it]++;
        }

        int ans = 0;

        for (auto& it : ansFreq) {
            int sameColorCount = it.first;
            int rabbitCount = it.second;

            int groupSize = sameColorCount + 1;
            int groupCount = ceil((double)rabbitCount / groupSize);

            ans += groupCount * groupSize;
        }

        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
