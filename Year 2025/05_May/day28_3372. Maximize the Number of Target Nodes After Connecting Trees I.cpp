// Problem Link -> https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/

class Solution {
public:
    int bfs(int startNode, unordered_map<int, vector<int>>& adjacencyList,
            int maxDistance, int totalNodes) {

        queue<pair<int, int>> traversalQueue;
        traversalQueue.push({startNode, 0});
        vector<bool> visited(totalNodes, false);
        visited[startNode] = true;

        int reachableNodesCount = 0;
        while (!traversalQueue.empty()) {
            int currentNode = traversalQueue.front().first;
            int currentDistance = traversalQueue.front().second;
            traversalQueue.pop();

            if (currentDistance > maxDistance) {
                continue;
            }

            reachableNodesCount++;

            for (auto& neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    traversalQueue.push({neighbor, currentDistance + 1});
                }
            }
        }

        return reachableNodesCount;
    }

    vector<int> findReachableNodes(vector<vector<int>>& treeEdges,
                                   int distanceLimit) {
        int totalNodes = treeEdges.size() + 1;
        unordered_map<int, vector<int>> adjacencyList;
        
        for (auto& edge : treeEdges) {
            int nodeU = edge[0];
            int nodeV = edge[1];
            adjacencyList[nodeU].push_back(nodeV);
            adjacencyList[nodeV].push_back(nodeU);
        }

        vector<int> reachableNodesList(totalNodes);
        for (int node = 0; node < totalNodes; node++) {
            reachableNodesList[node] =
                bfs(node, adjacencyList, distanceLimit, totalNodes);
        }

        return reachableNodesList;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int totalNodes = edges1.size() + 1;

        vector<int> reachableFromTree1 = findReachableNodes(edges1, k);
        vector<int> reachableFromTree2 = findReachableNodes(edges2, k - 1);

        int maxReachableInTree2 =
            *max_element(begin(reachableFromTree2), end(reachableFromTree2));

        for (int i = 0; i < reachableFromTree1.size(); i++) {
            reachableFromTree1[i] += maxReachableInTree2;
        }

        return reachableFromTree1;
    }
};



// Time Complexity -> O(V*(V+E))
// Space Complexity -> O(V+E)
