// Problem Link -> https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

class Solution {
public:
    int dfs(int currBox, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_set<int>& openedBoxes, unordered_set<int>& pendingBoxes) {

        if (openedBoxes.count(currBox)) {
            return 0;
        }

        if (status[currBox] == 0) {
            pendingBoxes.insert(currBox);
            return 0;
        }

        openedBoxes.insert(currBox);
        int totalCandies = candies[currBox];

        for (int& innerBox : containedBoxes[currBox]) {
            totalCandies += dfs(innerBox, status, candies, keys, containedBoxes,
                                openedBoxes, pendingBoxes);
        }

        for (int& key : keys[currBox]) {
            status[key] = 1;
            if (pendingBoxes.count(key)) {
                totalCandies += dfs(key, status, candies, keys, containedBoxes,
                                    openedBoxes, pendingBoxes);
            }
        }

        return totalCandies;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int totalCandies = 0;
        unordered_set<int> openedBoxes;
        unordered_set<int> pendingBoxes;

        for (int& startBox : initialBoxes) {
            totalCandies += dfs(startBox, status, candies, keys, containedBoxes,
                                        openedBoxes, pendingBoxes);
        }

        return totalCandies;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(n)
