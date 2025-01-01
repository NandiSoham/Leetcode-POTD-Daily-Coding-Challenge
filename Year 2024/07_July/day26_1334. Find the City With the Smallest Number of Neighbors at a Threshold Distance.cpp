// Problem Link -> https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    void floydWarshall(int n, vector<vector<int>>& distanceMatrix) {
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    distanceMatrix[i][j] = min(distanceMatrix[i][j], distanceMatrix[i][via] + distanceMatrix[via][j]);
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& distanceMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int city = 0; city < n; city++) {
            int reachableCount = 0;
            for (int otherCity = 0; otherCity < n; otherCity++) {
                if (city != otherCity && distanceMatrix[city][otherCity] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = city;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distanceMatrix(n, vector<int>(n, 1e9 + 7));

        for (int i = 0; i < n; i++) {
            distanceMatrix[i][i] = 0;  
        }

        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            distanceMatrix[from][to] = weight;
            distanceMatrix[to][from] = weight;
        }

        floydWarshall(n, distanceMatrix);

        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(n^2)
