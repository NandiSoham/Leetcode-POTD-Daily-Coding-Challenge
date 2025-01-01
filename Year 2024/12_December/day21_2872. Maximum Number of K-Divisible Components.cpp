// Problem Link -> https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

class Solution {
public:
    int depthFirstSearch(vector<vector<int>>& adjacencyList, vector<int>& nodeValues, int& divisor, int& componentCount, int currentNode, int parentNode = -1) {
        long long currentSum = nodeValues[currentNode];
        for (int neighbor : adjacencyList[currentNode]) {
            if (neighbor != parentNode) {
                currentSum += depthFirstSearch(adjacencyList, nodeValues, divisor, componentCount, neighbor, currentNode);
            }
        }
        currentSum %= divisor;
        if (currentSum == 0) {
            componentCount++;
        }
        return currentSum;
    }

    int maxKDivisibleComponents(int nodeCount, vector<vector<int>>& edges, vector<int>& nodeValues, int divisor) {
        vector<vector<int>> adjacencyList(nodeCount);
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        int componentCount = 0;
        depthFirstSearch(adjacencyList, nodeValues, divisor, componentCount, 0);
        return componentCount;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
