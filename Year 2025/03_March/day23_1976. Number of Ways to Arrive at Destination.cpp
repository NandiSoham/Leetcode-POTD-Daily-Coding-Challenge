// Problem Link -> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    typedef pair<long long, int> MinHeapPair;
    const int MODULO = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto& road : roads) {
            int start = road[0];
            int end = road[1];
            int travelTime = road[2];
            adjList[start].push_back({end, travelTime});
            adjList[end].push_back({start, travelTime});
        }

        priority_queue<MinHeapPair, vector<MinHeapPair>, greater<MinHeapPair>> minHeap;
        vector<long long> minTime(n, LLONG_MAX);
        vector<int> pathWays(n, 0);

        minTime[0] = 0;
        pathWays[0] = 1;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            long long currTime = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            for (auto& neighbor : adjList[currNode]) {
                int adjacentNode = neighbor.first;
                int timeToTravel = neighbor.second;

                if (currTime + timeToTravel < minTime[adjacentNode]) {
                    minTime[adjacentNode] = currTime + timeToTravel;
                    pathWays[adjacentNode] = pathWays[currNode];
                    minHeap.push({minTime[adjacentNode], adjacentNode});

                } else if (currTime + timeToTravel == minTime[adjacentNode]) {
                    pathWays[adjacentNode] = (pathWays[adjacentNode] + pathWays[currNode]) % MODULO;
                }
            }
        }

        return pathWays[n - 1];
    }
};



//Time Complexity -> O(((V+E)*log(V))
//Space Complexity -> O(V+E)
