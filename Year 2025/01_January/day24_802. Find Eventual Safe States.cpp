// Problem Link -> https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    bool detectCycleDFS(vector<vector<int>>& graph, int node,
                        vector<bool>& isVisited, vector<bool>& recursionStack) {
        isVisited[node] = true;
        recursionStack[node] = true;

        for (int& neighbour : graph[node]) {
            if (isVisited[neighbour] == false &&
                detectCycleDFS(graph, neighbour, isVisited, recursionStack))
                return true;
            else if (recursionStack[neighbour])
                return true;
        }

        recursionStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        vector<bool> isVisited(nodeCount, false);
        vector<bool> recursionStack(nodeCount, false);
        vector<int>safeNodes;

        for(int node = 0; node < nodeCount; node++){
            if (!isVisited[node]) {
                detectCycleDFS(graph, node, isVisited, recursionStack);
            }
        }

        for(int i = 0; i < nodeCount; i++){
            if (!recursionStack[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};



// Time Complexity -> O(V + E)
// Space Complexity -> O(V + E)
