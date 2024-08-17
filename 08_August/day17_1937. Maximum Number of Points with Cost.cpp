// Problem Link -> https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

class Solution {
public:
    typedef long long ll;

    ll maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<ll> previousRow(cols);

        for(int col = 0; col < cols; col++) {
            previousRow[col] = points[0][col];
        }

        for(int row = 1; row < rows; row++) {
            vector<ll> currentRow(cols);
            vector<ll> maxLeft(cols), maxRight(cols);

            maxLeft[0] = previousRow[0];
            for(int col = 1; col < cols; col++) {
                maxLeft[col] = max(previousRow[col], maxLeft[col - 1] - 1);
            }

            maxRight[cols - 1] = previousRow[cols - 1];
            for(int col = cols - 2; col >= 0; col--) {
                maxRight[col] = max(previousRow[col], maxRight[col + 1] - 1);
            }

            for(int col = 0; col < cols; col++) {
                currentRow[col] = points[row][col] + max(maxLeft[col], maxRight[col]);
            }
            
            previousRow = currentRow;
        }

        return *max_element(previousRow.begin(), previousRow.end());
    }
};



// Time COmplexity -> O(m*n)
// Space COmplexity -> O(n)
