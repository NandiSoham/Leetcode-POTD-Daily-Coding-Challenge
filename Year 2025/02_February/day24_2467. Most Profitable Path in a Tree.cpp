// Problem Link -> https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome = INT_MIN;

    bool DFSBob(int curr, int t, vector<bool>& visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if (curr == 0) return true;

        for (int ngbr : adj[curr]) {
            if (!visited[ngbr] && DFSBob(ngbr, t + 1, visited)) {
                return true;
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        // Income update based on Bob's arrival time
        if (!bobMap.count(curr) || t < bobMap[curr]) {
            income += amount[curr];
        } else if (t == bobMap[curr]) {
            income += amount[curr] / 2;
        }

        // If leaf node (except node 0), update max income
        if (adj[curr].size() == 1 && curr != 0) {
            aliceIncome = max(aliceIncome, income);
        }

        for (int ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        // Construct adjacency list
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // DFS to find Bob's arrival times at each node
        vector<bool> visited(n, false);
        DFSBob(bob, 0, visited);

        // DFS for Alice to find max income path
        visited.assign(n, false);
        DFSAlice(0, 0, 0, visited, amount);

        return aliceIncome;
    }
};



// Time Complexity ->O(n)
// Space Complexity -> O(n)

// =========================================================================================
