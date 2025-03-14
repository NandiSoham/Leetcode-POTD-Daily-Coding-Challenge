// Problem Link -> https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

// ======================================= Approach - 1 (Brute Force - TLE) ====================================

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCandies = 0;

        for(int i = 0; i < n; i++){
            maxCandies = max(maxCandies, candies[i]);
        }

        for(int candy = maxCandies; candy >= 1; candy--){
            int count = 0;

            for(int i = 0; i < n; i++){
                count += candies[i] / candy;
            }

            if(count >= k) return candy;
        }

        return 0;
    }
};


// =============================================================================================================
