// Problem Link -> https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/

class Solution {
public:
    unordered_map<int, vector<int>> adjacencyList;

    int findShortestPath(int totalNodes) {
        queue<int> nodesQueue;
        nodesQueue.push(0);
        vector<bool> visited(totalNodes, false);
        visited[0] = true;

        int distance = 0;
        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            while (levelSize--) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();

                if (currentNode == totalNodes - 1) {
                    return distance;
                }

                for (int neighbor : adjacencyList[currentNode]) {
                    if (!visited[neighbor]) {
                        nodesQueue.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            distance++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int totalNodes, vector<vector<int>>& queries) {
        adjacencyList.clear();

        for (int node = 0; node < totalNodes - 1; node++) {
            adjacencyList[node].push_back(node + 1);
        }

        int totalQueries = queries.size();
        vector<int> results(totalQueries);

        for (int queryIndex = 0; queryIndex < totalQueries; queryIndex++) {
            int fromNode = queries[queryIndex][0];
            int toNode = queries[queryIndex][1];
            adjacencyList[fromNode].push_back(toNode);

            results[queryIndex] = findShortestPath(totalNodes);
        }

        return results;
    }
};
