// Problem link -> https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

class Solution {
public:
    int bfs(vector<vector<int>>& graph, int start, int totalNodes) {
        vector<bool> visited(totalNodes + 1, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int levelCount = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            levelCount++;
        }

        return levelCount;
    }

    int findMaxDistance(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& distances) {
        if (visited[node]) return distances[node];

        visited[node] = true;
        int maxDistance = distances[node];
        for (int neighbor : graph[node]) {
            maxDistance = max(maxDistance, findMaxDistance(graph, neighbor, visited, distances));
        }

        return maxDistance;
    }

    int getMaxGroupCount(vector<vector<int>>& graph, int totalNodes) {
        vector<int> distances(totalNodes + 1, 0);
        for (int i = 1; i <= totalNodes; i++) {
            distances[i] = bfs(graph, i, totalNodes);
        }

        int maxCount = 0;
        vector<int> visited(totalNodes + 1, false);
        for (int i = 1; i <= totalNodes; i++) {
            if (!visited[i]) {
                maxCount += findMaxDistance(graph, i, visited, distances);
            }
        }
        return maxCount;
    }

    void checkBipartite(vector<vector<int>>& graph, vector<int>& visited, int node, bool& isValid, int color) {
        if (visited[node] != -1) {
            isValid &= (color == visited[node]);
            return;
        }

        visited[node] = color;
        for (int neighbor : graph[node]) {
            checkBipartite(graph, visited, neighbor, isValid, 1 - color);
        }
    }

    int magnificentSets(int totalNodes, vector<vector<int>>& edges) {
        vector<vector<int>> graph(totalNodes + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(totalNodes + 1, -1);
        bool isBipartite = true;

        for (int i = 1; i <= totalNodes; i++) {
            if (isBipartite && visited[i] == -1) {
                checkBipartite(graph, visited, i, isBipartite, 1);
            }
        }

        if (!isBipartite) return -1;

        return getMaxGroupCount(graph, totalNodes);
    }
};



// Time Complexity -> O(V+(V+E))
// Space Complexity -> O(V+E)
