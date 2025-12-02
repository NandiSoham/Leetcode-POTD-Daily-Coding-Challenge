// Problem Link -> https://leetcode.com/problems/count-number-of-trapezoids-i/description/

class Solution {
public:
    int M = 1e9+7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp; 

        for(auto &point : points) {
            int y = point[1];
            mp[y]++;
        }

        long long result = 0; 

        long long prevHorizontalLines = 0;

        for(auto &it : mp) {
            int count = it.second;

            long long horizontalLines = (long long)count * (count-1)/2; 

            result += horizontalLines * prevHorizontalLines;

            prevHorizontalLines += horizontalLines;
        }

        return result % M;


    }
};



// Time complexity -> O(n)
// Space Complexity -> O(n)
