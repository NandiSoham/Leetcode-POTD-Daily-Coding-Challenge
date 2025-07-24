// Problem Link -> https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/

class Solution {
public:
    void dfs(int current, int parent, vector<int>& xorSubtree,
             vector<int>& entry, vector<int>& exit, int& time,
             vector<int>& nums, unordered_map<int, vector<int>>& graph) {

        xorSubtree[current] = nums[current];
        entry[current] = time;
        time++;

        for (int& neighbor : graph[current]) {
            if (neighbor != parent) {
                dfs(neighbor, current, xorSubtree, entry, exit, time, nums,
                    graph);
                xorSubtree[current] ^= xorSubtree[neighbor];
            }
        }

        exit[current] = time;
        time++;
    }

    bool isAncestor(int anc, int desc, vector<int>& entry, vector<int>& exit) {
        return entry[desc] >= entry[anc] && exit[desc] <= exit[anc];
    }

    int computeScore(int val1, int val2, int val3) {
        int maxVal = max({val1, val2, val3});
        int minVal = min({val1, val2, val3});
        return maxVal - minVal;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int totalNodes = nums.size();

        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }

        vector<int> xorSubtree(totalNodes, 0);
        vector<int> entry(totalNodes, 0);
        vector<int> exit(totalNodes, 0);
        int time = 0;

        dfs(0, -1, xorSubtree, entry, exit, time, nums, graph);

        int minScore = INT_MAX;
        for (int i = 1; i < totalNodes; i++) {
            for (int j = i + 1; j < totalNodes; j++) {
                int val1, val2, val3;

                if (isAncestor(i, j, entry, exit)) {
                    val1 = xorSubtree[j];
                    val2 = xorSubtree[i] ^ xorSubtree[j];
                    val3 = xorSubtree[0] ^ val1 ^ val2;
                } else if (isAncestor(j, i, entry, exit)) {
                    val1 = xorSubtree[i];
                    val2 = xorSubtree[j] ^ xorSubtree[i];
                    val3 = xorSubtree[0] ^ val1 ^ val2;
                } else {
                    val1 = xorSubtree[i];
                    val2 = xorSubtree[j];
                    val3 = xorSubtree[0] ^ val1 ^ val2;
                }

                minScore = min(minScore, computeScore(val1, val2, val3));
            }
        }

        return minScore;
    }
};



