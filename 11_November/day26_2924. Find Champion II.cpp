// Problem Link -> https://leetcode.com/problems/find-champion-ii/description/

class Solution {
public:
    int findChampion(int totalNodes, vector<vector<int>>& connections) {
        vector<int> incomingEdges(totalNodes, 0);
        
        for (vector<int>& connection : connections) {
            int fromNode = connection[0];
            int toNode = connection[1];
            incomingEdges[toNode]++;
        }
        
        int championNode = -1;
        int zeroIncomingCount = 0;
        
        for (int node = 0; node < totalNodes; node++) {
            if (incomingEdges[node] == 0) {
                championNode = node;
                zeroIncomingCount++;
                if (zeroIncomingCount > 1) {
                    return -1;
                }
            }
        }
        return championNode;
    }
};



// Time Complexity -> O(m + n)
// Space Complexity -> O(n)
