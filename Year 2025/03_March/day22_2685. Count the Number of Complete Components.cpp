// Problem Link -> https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
public:
    void exploreComponent(int node, unordered_map<int, vector<int>>& adjList, vector<bool>& visitedNodes, int& vertexCount, int& edgeCount) {
        visitedNodes[node] = true;
        vertexCount++;
        edgeCount += adjList[node].size();

        for(int &neighbor : adjList[node]) {
            if(!visitedNodes[neighbor]) {
                exploreComponent(neighbor, adjList, visitedNodes, vertexCount, edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;

        int completeComponents = 0;

        for(auto &edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            adjList[n1].push_back(n2);
            adjList[n2].push_back(n1);
        }

        vector<bool> visitedNodes(n, false);
        for(int i = 0; i < n; i++) {
            if(visitedNodes[i] == true) {
                continue;
            }
            int vertexCount = 0;
            int edgeCount = 0;
            exploreComponent(i, adjList, visitedNodes, vertexCount, edgeCount);

            if((vertexCount * (vertexCount - 1)) == edgeCount) {
                completeComponents++;
            }
        }
        
        return completeComponents;
    }
};
