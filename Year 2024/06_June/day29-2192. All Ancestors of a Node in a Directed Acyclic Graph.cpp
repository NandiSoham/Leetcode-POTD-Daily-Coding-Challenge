// Problem Link -> https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

class Solution {
public:
    void depthFirstSearch(int currentNode,
                          unordered_map<int, vector<int>>& adjacencyList,
                          vector<bool>& visitedNodes) {
        visitedNodes[currentNode] = true;

        for (int& neighbor : adjacencyList[currentNode]) {
            if (!visitedNodes[neighbor]) {
                depthFirstSearch(neighbor, adjacencyList, visitedNodes);
            }
        }
    }

    vector<vector<int>> getAncestors(int totalNodes,
                                     vector<vector<int>>& edges) {
        vector<vector<int>> ancestorsList;
        unordered_map<int, vector<int>> adjacencyList;

        // Building the adjacency list
        for (vector<int>& edge : edges) {
            int parent = edge[0];
            int child = edge[1];
            adjacencyList[child].push_back(parent); // child --> parent
        }

        // ancestors for each node
        for (int node = 0; node < totalNodes; node++) {
            vector<int> ancestors;
            vector<bool> visitedNodes(totalNodes, false);
            depthFirstSearch(node, adjacencyList, visitedNodes);

            for (int i = 0; i < totalNodes; i++) {
                if (i == node)
                    continue;

                if (visitedNodes[i]) {
                    ancestors.push_back(i);
                }
            }

            ancestorsList.push_back(ancestors);
        }

        return ancestorsList;
    }
};



// Time Complexity -> O(V * (V+E)) , V = number of vertices and E = number of edges
// Space Complexity -> O(V+E)
