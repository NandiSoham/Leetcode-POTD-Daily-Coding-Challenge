// problem Link -> https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int maxArea = 0;

        for(int i = 0; i < dimensions.size(); i++){
            int len = dimensions[i][0];
            int wid = dimensions[i][1];

            int currDiag = (len*len) + (wid * wid);
            int currArea = len * wid;

            if(currDiag > maxDiag){
                maxDiag = currDiag;
                maxArea = currArea;
            } else if(currDiag == maxDiag){
                maxArea = max(maxArea, currArea);
            }
        }

        return maxArea;
    }
};


// Time Copmplexity -> O(n)
// SPace Complexity -> O(1)
