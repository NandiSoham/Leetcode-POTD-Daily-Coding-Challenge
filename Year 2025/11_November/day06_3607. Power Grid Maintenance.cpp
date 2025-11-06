// Problem Link -> https://leetcode.com/problems/power-grid-maintenance/description/

class Solution {
public:
    unordered_map<int, set<int>> groupNodes; 

    void traverse(int node, unordered_map<int, vector<int>>& graph,
                  vector<int>& seen, int groupId, vector<int>& belongs) {
        seen[node] = 1;
        belongs[node] = groupId;
        groupNodes[groupId].insert(node);

        for (int neighbor : graph[node]) {
            if (!seen[neighbor]) {
                traverse(neighbor, graph, seen, groupId, belongs);
            }
        }
    }

    vector<int> processQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        vector<int> seen(n + 1, 0);
        vector<int> belongs(n + 1);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                traverse(i, graph, seen, i, belongs);
            }
        }

        vector<int> answers;

        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int groupId = belongs[x];

            if (type == 1) {
                if (groupNodes[groupId].count(x)) {
                    answers.push_back(x);
                } else if (!groupNodes[groupId].empty()) {
                    answers.push_back(*groupNodes[groupId].begin());
                } else {
                    answers.push_back(-1);
                }
            } else {
                groupNodes[groupId].erase(x);
            }
        }

        return answers;
    }
};
