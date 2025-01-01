// Problem Link -> https://leetcode.com/problems/rank-transform-of-an-array/description/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> numToRank; 
        set<int> sortedSet(begin(arr), end(arr)); 
        int currentRank = 1;

        for (auto &num : sortedSet) {
            numToRank[num] = currentRank;
            currentRank++;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }

        return arr;
    }
};


//Time Complexity -> O(n*logn)
//Space Complexity -> O(n)
