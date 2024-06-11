class Solution {
public:

    vector<int> findLeftMax(vector<int>& height, int& n){
        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for(int  i= 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }

    vector<int> findRightMax(vector<int> &height, int &n){
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];

        for(int  i= n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int heightSum = 0;

        vector<int> leftMax = findLeftMax(height, n);
        vector<int> rightMax = findRightMax(height, n);

        for(int i = 0; i < n; i++){
            int curHeight = min(leftMax[i], rightMax[i]) - height[i];
            heightSum += curHeight;
        }

        return heightSum;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/trapping-rain-water/description/
