// Problem link -> https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/

class Solution {
public:
    unordered_map<int, vector<int>>
    buildAdjacencyList(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;
        for (auto& edge : edges) {
            int nodeU = edge[0];
            int nodeV = edge[1];
            adjacencyList[nodeU].push_back(nodeV);
            adjacencyList[nodeV].push_back(nodeU);
        }
        return adjacencyList;
    }

    void depthFirstSearch(int currentNode,
                          unordered_map<int, vector<int>>& adjacencyList,
                          int parentNode, vector<int>& nodeMarks,
                          int& zeroMarkCount, int& oneMarkCount) {
        if (nodeMarks[currentNode] == 0) {
            zeroMarkCount++;
        } else {
            oneMarkCount++;
        }

        for (auto& neighbor : adjacencyList[currentNode]) {
            if (neighbor != parentNode) {
                nodeMarks[neighbor] = (nodeMarks[currentNode] == 0) ? 1 : 0;
                depthFirstSearch(neighbor, adjacencyList, currentNode,
                                 nodeMarks, zeroMarkCount, oneMarkCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int totalNodesA = edges1.size() + 1;
        int totalNodesB = edges2.size() + 1;

        unordered_map<int, vector<int>> adjacencyListA = buildAdjacencyList(edges1);
        unordered_map<int, vector<int>> adjacencyListB = buildAdjacencyList(edges2);

        vector<int> nodeMarksA(totalNodesA, -1);
        nodeMarksA[0] = 0;
        int countZeroA = 0;
        int countOneA = 0;
        depthFirstSearch(0, adjacencyListA, -1, nodeMarksA, countZeroA, countOneA);

        vector<int> nodeMarksB(totalNodesB, -1);
        nodeMarksB[0] = 0;
        int countZeroB = 0;
        int countOneB = 0;
        depthFirstSearch(0, adjacencyListB, -1, nodeMarksB, countZeroB, countOneB);

        int maxCountFromTreeB = max(countZeroB, countOneB);

        vector<int> maxTargetList(totalNodesA);
        for (int i = 0; i < totalNodesA; i++) {
            maxTargetList[i] = (nodeMarksA[i] == 0 ? countZeroA : countOneA) +
                               maxCountFromTreeB;
        }

        return maxTargetList;
    }
};


// time Complexity -> O(V+E)
// Space Complexity -> O(V+E)
