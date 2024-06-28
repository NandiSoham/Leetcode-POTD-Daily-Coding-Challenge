// Problem Link -> https://leetcode.com/problems/maximum-total-importance-of-roads/description/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degreeArr(n, 0);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];

            degreeArr[u]++;
            degreeArr[v]++;
        }

        sort(degreeArr.begin(), degreeArr.end());

        long long importanceVal = 1;
        long long totalImportance = 0;

        for(int i = 0; i < n; i++){
            totalImportance += degreeArr[i] * importanceVal;
            importanceVal++;
        }

        return totalImportance;
    }
};



// Time Complexity -> O(nlogn + E) where E = no. of edges
// Space Complexity -> O(n)
