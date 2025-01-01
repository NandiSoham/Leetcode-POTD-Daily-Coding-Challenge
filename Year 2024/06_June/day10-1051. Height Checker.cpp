// Problem Link -> https://leetcode.com/problems/height-checker/description/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heightArrCopy(heights);
        sort(heightArrCopy.begin(), heightArrCopy.end());
        int count = 0;

        for(int i = 0; i < heights.size(); i++){
            if(heightArrCopy[i] != heights[i])
                count++;
        }

        return count;
    }
};


// Time Complexity -> O(n + nlogn)
// Space Complexity -> O(n)
