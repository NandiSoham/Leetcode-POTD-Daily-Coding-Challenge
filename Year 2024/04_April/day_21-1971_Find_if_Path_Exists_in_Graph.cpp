class Solution {
public:

    bool pathCheck(unordered_map<int, vector<int>>& adj, int source, int destination, vector<bool>& isVisited){
        if(source == destination) return true;
        if(isVisited[source] == true) return false;
        isVisited[source] = true;

        for(auto &node : adj[source]){
            if(pathCheck(adj, node, destination, isVisited) == true)
                return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(source == destination)
            return true;
            
        unordered_map<int, vector<int>> adj;
        for(vector<int> &it : edges){
            int x = it[0];
            int y = it[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<bool> isVisited(n, false);

        return pathCheck(adj, source, destination, isVisited);
    }
};



// Time Complexity -> O(m X n)
// Space Complexity -> O(1)
// problem Link -> https://leetcode.com/problems/find-if-path-exists-in-graph/description/
