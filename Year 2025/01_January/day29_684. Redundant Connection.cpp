// Problem Link -> https://leetcode.com/problems/redundant-connection/description/

class Solution {
public:
    bool dfsFunc(unordered_map<int, vector<int>>& graph, int start, int target, vector<bool>& visited) {
        visited[start] = true;

        if (start == target) {
            return true;
        }

        for (int& neighbor : graph[start]) {
            if (visited[neighbor]) continue;

            if (dfsFunc(graph, neighbor, target, visited)) {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int totalNodes = edges.size(); 

        unordered_map<int, vector<int>> graph;

        for (const auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            
            vector<bool> visited(totalNodes, false);
            if (graph.count(nodeA) && graph.count(nodeB) && dfsFunc(graph, nodeA, nodeB, visited)) {
                return edge;
            }

            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }

        return {};
    }
};



// Time Complexity -> O(n^2)
// Space complexity -> O(n)
