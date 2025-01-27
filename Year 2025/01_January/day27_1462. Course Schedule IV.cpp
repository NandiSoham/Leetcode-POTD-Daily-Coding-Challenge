// Problem Link -> https://leetcode.com/problems/course-schedule-iv/description/

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int start, int target,
             vector<bool>& visited) {
        visited[start] = true;

        if (start == target) 
            return true;

        bool canReach = false;
        for (auto& neighbor : graph[start]) {
            if (!visited[neighbor]) {
                canReach = canReach || dfs(graph, neighbor, target, visited);
            }
        }

        return canReach;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : prerequisites) {
            int from = edge[0];
            int to = edge[1];

            graph[from].push_back(to);
        }

        int queryCount = queries.size();
        vector<bool> results(queryCount);
        for (int i = 0; i < queryCount; i++) {
            int source = queries[i][0];
            int destination = queries[i][1];

            vector<bool> visited(numCourses, false);
            results[i] = dfs(graph, source, destination, visited);
        }

        return results;
    }
};



// Time Complexity -> O(Q⋅(V+E))
// Space Complexity -> O(V+E)
