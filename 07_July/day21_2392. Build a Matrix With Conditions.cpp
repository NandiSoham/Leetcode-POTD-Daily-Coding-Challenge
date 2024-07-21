// problem Link -> https://leetcode.com/problems/build-a-matrix-with-conditions/description/

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& edges, int numNodes) {
        unordered_map<int, vector<int>> adjacencyList;
        stack<int> stack;
        vector<int> topologicalOrder;
        vector<int> visitStatus(numNodes + 1, 0); 
        bool hasCycle = false;

        for (vector<int>& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
        }

        for (int node = 1; node <= numNodes; node++) {
            if (visitStatus[node] == 0) {
                depthFirstSearch(node, adjacencyList, visitStatus, stack, hasCycle);
                if (hasCycle) {
                    return {}; 
                }
            }
        }
        
        while (!stack.empty()) {
            topologicalOrder.push_back(stack.top());
            stack.pop();
        }
        return topologicalOrder;
    }

    void depthFirstSearch(int node, unordered_map<int, vector<int>>& adjacencyList, 
                          vector<int>& visitStatus, stack<int>& stack, bool& hasCycle) {
        
        visitStatus[node] = 1;
        for (int& neighbor : adjacencyList[node]) {
            if (visitStatus[neighbor] == 0) {
                depthFirstSearch(neighbor, adjacencyList, visitStatus, stack, hasCycle);
            } else if (visitStatus[neighbor] == 1) {
                hasCycle = true; 
                return;
            }
        }

        visitStatus[node] = 2; 
        stack.push(node); 
    }

    vector<vector<int>> buildMatrix(int size, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {        
        vector<int> rowOrder = topologicalSort(rowConditions, size);
        vector<int> columnOrder = topologicalSort(colConditions, size);

        if (rowOrder.empty() || columnOrder.empty())
            return {};

        vector<vector<int>> matrix(size, vector<int>(size, 0));
        unordered_map<int, int> positionMap;
        for (int i = 0; i < size; i++) {
            positionMap[rowOrder[i]] = i;
        }

        for (int j = 0; j < size; j++) {
            int element = columnOrder[j];
            if (positionMap.find(element) != positionMap.end()) {
                matrix[positionMap[element]][j] = element;
            }
        }
        return matrix;
    }
};



//Time Complexity -> O(k*^2 + n)
//Space Complexity -> O(k*^2 + n)