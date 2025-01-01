// Problem Link -> https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/


class Solution {
public:
    int numNodes;
    
    pair<int, int> findFarthestNode(unordered_map<int, vector<int>>& adjacencyList, int startNode) {
        queue<int> nodesQueue;
        nodesQueue.push(startNode);

        unordered_map<int, bool> visitedNodes;
        visitedNodes[startNode] = true;

        int maxDistance = 0;
        int farthestNode = startNode;

        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();

            while (levelSize--) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();

                farthestNode = currentNode;

                for (auto& neighbor : adjacencyList[currentNode]) {
                    if (!visitedNodes[neighbor]) {
                        visitedNodes[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) {
                maxDistance++;
            }
        }

        return {farthestNode, maxDistance};
    }

    int calculateDiameter(unordered_map<int, vector<int>> adjacencyList) {
        auto [firstFarthestNode, _] = findFarthestNode(adjacencyList, 0);
        auto [_, diameter] = findFarthestNode(adjacencyList, firstFarthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> createAdjacencyList(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;

        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        return adjacencyList;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adjacencyList1 = createAdjacencyList(edges1);
        unordered_map<int, vector<int>> adjacencyList2 = createAdjacencyList(edges2);

        int diameter1 = calculateDiameter(adjacencyList1);
        int diameter2 = calculateDiameter(adjacencyList2);

        int combinedDiameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }
};



// Time Complexity -> O(V+E)
// Space Complexity -> O(V+E)
