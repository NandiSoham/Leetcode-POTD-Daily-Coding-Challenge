// Problem Link -> https://leetcode.com/problems/valid-arrangement-of-pairs/description/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> inDegree, outDegree;

        for (auto& edge : pairs) {
            int fromNode = edge[0];
            int toNode = edge[1];

            adjacencyList[fromNode].push_back(toNode);
            outDegree[fromNode]++;
            inDegree[toNode]++;
        }

        int startNode = pairs[0][0];
        for (auto& node : adjacencyList) {
            int currentNode = node.first;
            if (outDegree[currentNode] - inDegree[currentNode] == 1) {
                startNode = currentNode;
                break;
            }
        }

        vector<int> eulerPath;
        stack<int> traversalStack;
        traversalStack.push(startNode);

        while (!traversalStack.empty()) {
            int currentNode = traversalStack.top();
            if (!adjacencyList[currentNode].empty()) {
                int neighbor = adjacencyList[currentNode].back();
                adjacencyList[currentNode].pop_back();
                traversalStack.push(neighbor);
            } else {
                eulerPath.push_back(currentNode);
                traversalStack.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());

        vector<vector<int>> result;
        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};



//Time Complexity -> O(V+E) 
//Space Complexity -> O(V+E)
