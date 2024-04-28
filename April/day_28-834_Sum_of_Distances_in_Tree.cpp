class Solution {
public:
    long root_node_result = 0;
    vector<int> child_node_count;
    int num_of_nodes;

    int find_result_for_root(unordered_map<int, vector<int>>& adj,
                             int curr_node, int prev_node, int curr_depth) {
        int total_node_count = 1;
        root_node_result += curr_depth;

        for (int& child : adj[curr_node]) {
            if (child == prev_node)
                continue;

            total_node_count +=
                find_result_for_root(adj, child, curr_node, curr_depth + 1);
        }

        child_node_count[curr_node] = total_node_count;

        return total_node_count;
    }

    void find_result_for_child_nodes(unordered_map<int, vector<int>>& adj,
                                     int parent_node, int prev_node,
                                     vector<int>& result) {

        for (int& child : adj[parent_node]) {
            if (child == prev_node)
                continue;

            result[child] = result[parent_node] - child_node_count[child] +
                            (num_of_nodes - child_node_count[child]);
            find_result_for_child_nodes(adj, child, parent_node, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        num_of_nodes = n;
        child_node_count.resize(n, 0);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root_node_result = 0;
        find_result_for_root(adj, 0, -1, 0);
        vector<int> result(n, 0);
        result[0] = root_node_result;
        find_result_for_child_nodes(adj, 0, -1, result);

        return result;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/sum-of-distances-in-tree/description/
