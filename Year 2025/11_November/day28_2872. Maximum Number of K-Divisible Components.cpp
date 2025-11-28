// Problem Link -> https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

class Solution {
public:
    int componentCount = 0;

    int dfs(int node, int parent, unordered_map<int, vector<int>>& graph, vector<int>& values, int k) {
        int rem = 0;

        for (int nxt : graph[node]) {
            if (nxt == parent)
                continue;

            rem += dfs(nxt, node, graph, values, k);
            rem %= k;
        }

        rem = (rem + values[node]) % k;
        if (rem == 0)
            componentCount++;

        return rem;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> graph;

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        componentCount = 0;
        dfs(0, -1, graph, values, k);

        return componentCount;
    }
};


//  Time Complexity -> O(n)
// Space Complexity -> O(n)
