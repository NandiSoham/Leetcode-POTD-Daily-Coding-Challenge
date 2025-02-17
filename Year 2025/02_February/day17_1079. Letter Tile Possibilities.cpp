// Problem Link -> https://leetcode.com/problems/letter-tile-possibilities/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& isUsed, unordered_set<string>& ans, string& currStr){
        ans.insert(currStr);

        for(int i = 0; i < n; i++){
            if(isUsed[i] == true) continue;

            currStr.push_back(tiles[i]);
            isUsed[i] = true;

            solve(tiles, isUsed, ans, currStr);

            isUsed[i] = false;
            currStr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> isUsed(n, false);
        unordered_set<string> ans;
        string currStr = "";

        solve(tiles, isUsed, ans, currStr);
        return ans.size() - 1;
    }
};



// Time Complexity -> O(n!)
// Space Complexity -> O(n * n!), total possible sequences = n! and each having n length

// =========================================================================================
