// Problem Link -> https://leetcode.com/problems/find-center-of-star-graph/description/

// ----------------------------------------- Approach - 1 -----------------------------------

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degreeMap;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            degreeMap[u]++;
            degreeMap[v]++;
        }

        for(auto &it : degreeMap){
            if(it.second == edges.size())
                return it.first;
        }

        return -1;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// ------------------------------------------------------------------------------------------
