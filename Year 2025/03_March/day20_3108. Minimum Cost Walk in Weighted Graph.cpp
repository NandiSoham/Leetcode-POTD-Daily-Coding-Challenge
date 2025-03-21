// Problem Link -> https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/


class Solution {
public:

    vector<int> parent;

    int findParent(int node) {
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void uniteComponents(int node1, int node2) {
        parent[node2] = node1;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        parent.resize(n);
        vector<int> componentCost(n); 
	    
	    for(int index = 0; index < n; index++) {
	        parent[index] = index;
            componentCost[index] = -1;
        }
        
        for (auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int weight = edge[2];
            
            int parent1 = findParent(node1);
            int parent2 = findParent(node2);
            
            if (parent1 != parent2) {
                componentCost[parent1] &= componentCost[parent2];
                uniteComponents(parent1, parent2);
            }

            componentCost[parent1] &= weight;
        }
        
        vector<int> result;
        for (auto &query : queries) {
            int source = query[0];
            int target = query[1];
            
            int parentSource = findParent(source);
            int parentTarget = findParent(target);
            
            if (source == target)
                result.push_back(0);
            else if (parentSource != parentTarget)
                result.push_back(-1);
            else
                result.push_back(componentCost[parentSource]);
        }
        return result;
    }
};
