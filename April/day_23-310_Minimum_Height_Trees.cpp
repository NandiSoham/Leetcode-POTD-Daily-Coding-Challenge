class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        
        // Initializing variables
        vector<int> minHeightTrees;
        vector<int> nodeDegree(n, 0); // Store degree of each node
        unordered_map<int, vector<int>> adjList; // Adjacency list representation
        
        // Building adjacency list and calculating node degrees
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            nodeDegree[u]++;
            nodeDegree[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // Using queue for BFS traversal
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (nodeDegree[i] == 1) 
                que.push(i);
        }
        
        // BFS traversal until only 1 or 2 nodes left
        while (n > 2) {
            int queSize = que.size();
            n -= queSize; 
            
            for (int i = 0; i < queSize; ++i) {
                int u = que.front();
                que.pop();
                
                // Updating node degrees and adding leaf nodes to queue
                for (int v : adjList[u]) {
                    nodeDegree[v]--;
                    if (nodeDegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        // Adding remaining nodes to result
        while (!que.empty()) {
            minHeightTrees.push_back(que.front());
            que.pop();
        }
        
        return minHeightTrees;
    }
};



// Time Complexity -> O(n + e) [here n is no of nodes and e is no of edges)
// Space Complexity -> O(n + e)
// Problem Link -> https://leetcode.com/problems/minimum-height-trees/description/
