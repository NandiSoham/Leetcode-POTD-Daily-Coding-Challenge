// Problem Link -> https://leetcode.com/problems/soup-servings/description/

class Solution {
public:
    vector<pair<int, int>> options{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> dp;

    double calculateProbablity(double soupA, double soupB){
        double totalProbablity = 0.0;

        if(soupA <= 0 && soupB <= 0) return 0.5;
        if(soupA <= 0) return 1.0;
        if(soupB <= 0) return 0.0;

        if(dp[soupA][soupB] != -1.0) 
            return dp[soupA][soupB];

        for(auto &it : options){
            int pourA = it.first;
            int pourB = it.second;

            totalProbablity += calculateProbablity(soupA - pourA, soupB - pourB);
        }

        return dp[soupA][soupB] = 0.25 * totalProbablity;
    }

    double soupServings(int n) {
        if(n >= 6000) return 1;

        dp.resize(n+1, vector<double>(n+1, -1.0));
        return calculateProbablity(n, n);
    }
};

