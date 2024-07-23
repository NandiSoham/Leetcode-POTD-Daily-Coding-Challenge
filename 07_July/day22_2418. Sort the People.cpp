// Problem Link -> https://leetcode.com/problems/sort-the-people/description/

// ------------------------------------- Approach - 1 --------------------------------

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        unordered_map<int, string> mp; 
        for(int i = 0; i < n; i++) {
            mp[heights[i]] = names[i];
        }

        sort(rbegin(heights), rend(heights));

        for(int i = 0; i < n; i++) {
            names[i] = mp[heights[i]];
        }

        return names;

    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// -----------------------------------------------------------------------------------
