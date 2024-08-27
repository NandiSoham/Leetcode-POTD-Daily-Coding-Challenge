// Problem Link -> https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adjacencyList;
        vector<double> ansArr(n, 0);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double probablity = succProb[i];
            adjacencyList[u].push_back({v, probablity});
            adjacencyList[v].push_back({u, probablity});
        }

        priority_queue<pair<double, int>> maxHeap;
        ansArr[start_node] = 1;
        maxHeap.push({1.0, start_node});

        while(!maxHeap.empty()){
            double currProb = maxHeap.top().first;
            int currNode = maxHeap.top().second;
            maxHeap.pop();

            for(auto &neighbours : adjacencyList[currNode]){
                int neighbourNode = neighbours.first;
                double neighbourProb = neighbours.second;

                if(ansArr[neighbourNode] < currProb * neighbourProb){
                    ansArr[neighbourNode] = currProb * neighbourProb;
                    maxHeap.push({ansArr[neighbourNode], neighbourNode});
                }
            }
        }

        return ansArr[end_node];
    }
};



// Time Complexity -> O(E*log(V))
// Space Complexity -> O(V + E)
