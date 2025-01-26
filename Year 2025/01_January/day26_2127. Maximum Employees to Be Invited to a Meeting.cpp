// Problem link -> https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que; 
        que.push({start, 0});
        int maxDistance = 0;

        while (!que.empty()) {
            auto [currNode, dist] = que.front();
            que.pop();

            for (auto& neighbor : adj[currNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    que.push({neighbor, dist + 1});
                    maxDistance = max(maxDistance, dist + 1);
                }
            }
        }

        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> reverseGraph;

        for (int i = 0; i < n; i++) {
            reverseGraph[favorite[i]].push_back(i);
        }

        int maxCycleSize = 0, totalHappyCoupleCount = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> nodeOrder;
                int currNode = i, nodeCount = 0;

                while (!visited[currNode]) {
                    visited[currNode] = true;
                    nodeOrder[currNode] = nodeCount++;

                    int nextNode = favorite[currNode];
                    if (nodeOrder.count(nextNode)) {
                        int cycleLength = nodeCount - nodeOrder[nextNode];
                        maxCycleSize = max(maxCycleSize, cycleLength);

                        if (cycleLength == 2) {
                            vector<bool> tempVisited(n, false);
                            tempVisited[currNode] = tempVisited[nextNode] = true;
                            totalHappyCoupleCount += 2 + BFS(currNode, reverseGraph, tempVisited) + BFS(nextNode, reverseGraph, tempVisited);
                        }
                        break;
                    }

                    currNode = nextNode;
                }
            }
        }

        return max(maxCycleSize, totalHappyCoupleCount);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
