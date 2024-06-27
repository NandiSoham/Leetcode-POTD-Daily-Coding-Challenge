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

// ----------------------------------------- Approach - 2 -----------------------------------

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstElement = edges[0];
        vector<int> secondElement = edges[1];

        if(firstElement[0] == secondElement[0] || firstElement[0] == secondElement[1]){
            return firstElement[0];
        }

        return firstElement[1];
    }
};



// Time Complexity -> O(1)
// Space Complexity -> O(1)

// ------------------------------------------------------------------------------------------
