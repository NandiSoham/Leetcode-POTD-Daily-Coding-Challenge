// Problem Link -> https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        int numNodes = colors.size();

        vector<int> inDegree(numNodes, 0);

        for (auto& edge : edges) {
            int fromNode = edge[0];
            int toNode = edge[1];

            adjList[fromNode].push_back(toNode);
            inDegree[toNode]++;
        }

        queue<int> topoQueue;
        vector<vector<int>> colorCount(numNodes, vector<int>(26, 0));

        for (int node = 0; node < numNodes; node++) {
            if (inDegree[node] == 0) {
                topoQueue.push(node);
                colorCount[node][colors[node] - 'a'] = 1;
            }
        }

        int maxColorValue = 0;
        int visitedNodes = 0;

        while (!topoQueue.empty()) {
            int currentNode = topoQueue.front();
            topoQueue.pop();

            visitedNodes++;
            maxColorValue =
                max(maxColorValue, colorCount[currentNode][colors[currentNode] - 'a']);

            for (int& neighbor : adjList[currentNode]) {
                for (int c = 0; c < 26; c++) {
                    colorCount[neighbor][c] = max(colorCount[neighbor][c],
                            colorCount[currentNode][c] +
                                (colors[neighbor] - 'a' == c));
                }

                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    topoQueue.push(neighbor);
                }
            }
        }

        if (visitedNodes < numNodes)
            return -1;

        return maxColorValue;
    }
};



// Time Com[lexity -> O(V + E)
// Space Complexity -> O(V + E)
