// Problem Link -> https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

class Solution {
public:
    void performBFS(const vector<int>& edges, int sourceNode,
                    vector<int>& distanceFromSource, int n) {
        queue<int> nodeQueue;
        nodeQueue.push(sourceNode);
        distanceFromSource[sourceNode] = 0;
        vector<bool> visited(n, false);
        visited[sourceNode] = true;

        while (!nodeQueue.empty()) {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            int nextNode = edges[currentNode];
            if (nextNode != -1 && !visited[nextNode]) {
                visited[nextNode] = true;
                distanceFromSource[nextNode] =
                    1 + distanceFromSource[currentNode];
                nodeQueue.push(nextNode);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> distanceFromNode1(n, INT_MAX);
        vector<int> distanceFromNode2(n, INT_MAX);

        performBFS(edges, node1, distanceFromNode1, n);
        performBFS(edges, node2, distanceFromNode2, n);

        int resultNode = -1;
        int minimumMaxDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (distanceFromNode1[i] != INT_MAX &&
                distanceFromNode2[i] != INT_MAX) {
                int currMaxDist = max(distanceFromNode1[i], distanceFromNode2[i]);

                if (minimumMaxDist > currMaxDist) {
                    resultNode = i;
                    minimumMaxDist = currMaxDist;
                }
            }
        }

        return resultNode;
    }
};



// Time Complexity -> O(V+E)
// Space Complexity -> O(n)
