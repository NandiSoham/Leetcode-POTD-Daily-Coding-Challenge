// Problem Link -> https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

class DisjointSetUnion {
private:
    vector<int> parent;
    vector<int> rank;
    int componentCount;

public:
    DisjointSetUnion(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        componentCount = size;
        for (int i = 1; i <= size; i++) {
            parent[i] = i;
        }
    }

    int findRoot(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findRoot(parent[node]);
    }

    void unionSets(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);

        if (root1 == root2)
            return;

        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root1] = root2;
            rank[root2]++;
        }
        componentCount--;
    }

    bool hasSingleComponent() {
        return componentCount == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int nodeCount, vector<vector<int>>& edges) {

        auto compareEdges = [&](vector<int>& edge1, vector<int>& edge2) {
            return edge1[0] > edge2[0];
        };

        sort(edges.begin(), edges.end(), compareEdges);

        DisjointSetUnion dsuAlice(nodeCount);
        DisjointSetUnion dsuBob(nodeCount);

        int edgesAdded = 0;

        for (auto& edge : edges) {
            int edgeType = edge[0];
            int node1 = edge[1];
            int node2 = edge[2];

            if (edgeType == 3) {
                bool added = false;

                if (dsuAlice.findRoot(node1) != dsuAlice.findRoot(node2)) {
                    dsuAlice.unionSets(node1, node2);
                    added = true;
                }

                if (dsuBob.findRoot(node1) != dsuBob.findRoot(node2)) {
                    dsuBob.unionSets(node1, node2);
                    added = true;
                }

                if (added)
                    edgesAdded++;

            } else if (edgeType == 2) {
                if (dsuBob.findRoot(node1) != dsuBob.findRoot(node2)) {
                    dsuBob.unionSets(node1, node2);
                    edgesAdded++;
                }
            } else {
                if (dsuAlice.findRoot(node1) != dsuAlice.findRoot(node2)) {
                    dsuAlice.unionSets(node1, node2);
                    edgesAdded++;
                }
            }
        }

        if (dsuAlice.hasSingleComponent() && dsuBob.hasSingleComponent()) {
            return edges.size() - edgesAdded;
        }

        return -1;
    }
};
