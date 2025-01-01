// Problem Link -> https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

class Solution {
public:
    #define P pair<int, int>

    int secondMinimum(int totalNodes, vector<vector<int>>& graphEdges, int travelTime, int signalChange) {
        unordered_map<int, vector<int>> adjacencyList(totalNodes + 1);
        for (auto& edge : graphEdges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }

        vector<int> firstMinTime(totalNodes + 1, INT_MAX);
        vector<int> secondMinTime(totalNodes + 1, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> minHeap;
        minHeap.push({0, 1});
        firstMinTime[1] = 0;

        while (!minHeap.empty()) {
            auto [passedTime, currentNode] = minHeap.top();
            minHeap.pop();

            if (secondMinTime[totalNodes] != INT_MAX && currentNode == totalNodes) { 
                return secondMinTime[totalNodes];
            }

            int signalCycles = passedTime / signalChange;
            if(signalCycles % 2 == 1) { // Red signal
                passedTime = signalChange * (signalCycles + 1); // Wait for green signal
            }

            for (auto& neighbor : adjacencyList[currentNode]) {
                if (firstMinTime[neighbor] > passedTime + travelTime) { 
                    secondMinTime[neighbor] = firstMinTime[neighbor];
                    firstMinTime[neighbor] = passedTime + travelTime;
                    minHeap.push({passedTime + travelTime, neighbor});
                } else if (secondMinTime[neighbor] > passedTime + travelTime && firstMinTime[neighbor] != passedTime + travelTime) {
                    secondMinTime[neighbor] = passedTime + travelTime;
                    minHeap.push({passedTime + travelTime, neighbor});
                }
            }
        }
        return -1;
    }
};
