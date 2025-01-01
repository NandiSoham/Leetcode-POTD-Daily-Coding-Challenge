// Problem Link -> https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& buildingHeights, vector<vector<int>>& queryPairs) {
        vector<int> results(queryPairs.size(), -1);

        unordered_map<int, vector<pair<int, int>>> buildingGroups;

        for (int queryIndex = 0; queryIndex < queryPairs.size(); queryIndex++) {
            auto& query = queryPairs[queryIndex];
            int leftIndex = min(query[0], query[1]);
            int rightIndex = max(query[0], query[1]);

            if (leftIndex == rightIndex || buildingHeights[rightIndex] > buildingHeights[leftIndex]) {
                results[queryIndex] = rightIndex;
            } else {
                int maxHeight = max(buildingHeights[leftIndex], buildingHeights[rightIndex]);
                buildingGroups[rightIndex].emplace_back(maxHeight, queryIndex);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pendingQueries;

        for (int currentIndex = 0; currentIndex < buildingHeights.size(); currentIndex++) {
            int currentHeight = buildingHeights[currentIndex];
            if (buildingGroups.find(currentIndex) != buildingGroups.end()) {
                for (auto& [queryHeight, queryIndex] : buildingGroups[currentIndex]) {
                    pendingQueries.emplace(queryHeight, queryIndex);
                }
            }

            while (!pendingQueries.empty() && currentHeight > pendingQueries.top().first) {
                auto [queryHeight, queryIndex] = pendingQueries.top();
                pendingQueries.pop();
                results[queryIndex] = currentIndex;
            }
        }

        return results;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
