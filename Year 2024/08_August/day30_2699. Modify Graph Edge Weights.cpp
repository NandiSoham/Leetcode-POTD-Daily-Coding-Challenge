// Problem Link -> https://leetcode.com/problems/modify-graph-edge-weights/description/

class Solution {
public:
    typedef long long ll;
    const int MAX_EDGE_WEIGHT = 2e9;
    typedef pair<long, long> NodePair;

    ll findShortestPath(vector<vector<int>>& edges, int numNodes, int source, int destination) {
        unordered_map<ll, vector<pair<ll, ll>>> adjacencyList; 

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int node1 = edge[0];
                int node2 = edge[1];
                int weight = edge[2];

                adjacencyList[node1].emplace_back(node2, weight);
                adjacencyList[node2].emplace_back(node1, weight);
            }
        }

        priority_queue<NodePair, vector<NodePair>, greater<NodePair>> minHeap;
        vector<ll> shortestDistances(numNodes, INT_MAX); 
        vector<bool> visited(numNodes, false);

        shortestDistances[source] = 0; 
        minHeap.push({0, source});

        while(!minHeap.empty()) {
            ll currentDistance = minHeap.top().first;
            ll currentNode = minHeap.top().second;
            minHeap.pop();

            if(visited[currentNode]) {
                continue;
            }
            visited[currentNode] = true;

            for(auto& [neighborNode, weight] : adjacencyList[currentNode]) {
                if(shortestDistances[neighborNode] > currentDistance + weight) {
                    shortestDistances[neighborNode] = currentDistance + weight;
                    minHeap.push({shortestDistances[neighborNode], neighborNode});
                }
            }
        }

        return shortestDistances[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int numNodes, vector<vector<int>>& edges, int source, int destination, int targetDistance) {
        ll currentShortestDistance = findShortestPath(edges, numNodes, source, destination);

        if(currentShortestDistance < targetDistance) {
            return {}; 
        }

        bool isTargetMatched = (currentShortestDistance == targetDistance);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {
                edge[2] = isTargetMatched ? MAX_EDGE_WEIGHT : 1; 

                if(!isTargetMatched) {
                    ll newShortestDistance = findShortestPath(edges, numNodes, source, destination);

                    if(newShortestDistance <= targetDistance) {
                        isTargetMatched = true;
                        edge[2] += (targetDistance - newShortestDistance);
                    }
                }
            }
        }

        if(!isTargetMatched) {
            return {}; 
        }
        return edges;
    }
};



// Time Complexity -> O(E * E * Log(V)) //E = number of edges, V = number of vertices/nodes
// Space Complexity -> O(V+E)
