// Problem Link -> https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int waterHold = 0;

        while(i < j){
            int h = min(height[i], height[j]);
            int w = j - i;
            int currWaterArea = h * w;

            waterHold = max(waterHold, currWaterArea);

            if(height[i] > height[j]) j--;
            else i++;
        }

        return waterHold;
    }
};


// Time Complexity -> O(n)
// Space complexity -> O(1)
