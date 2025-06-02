// Problem Link -> https://leetcode.com/problems/candy/description/

// ====================================== Approach - 1 ======================================

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = max(candies[i], candies[i - 1] + 1);
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            count += candies[i];
        }

        return count;
    
    }
};


// Time COmplexity -> O(n)
// Space Complexity -> O(n)

// ==========================================================================================


// ====================================== Approach - 1 ======================================

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int totalCandies = n;

        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i] > ratings[i - 1]){
                peak++;
                totalCandies += peak;
                i++;

                if(i == n) return totalCandies;
            }

            int dip = 0;
            while(i < n && ratings[i] < ratings[i - 1]){
                dip++;
                totalCandies += dip;
                i++;
            }
            totalCandies -= min(peak, dip);
        }

        return totalCandies;
    }
};


// Time COmplexity -> O(n)
// Space Complexity -> O(1)

// ==========================================================================================
