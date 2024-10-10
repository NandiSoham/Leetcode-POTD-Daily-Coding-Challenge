// Problem Link -> https://leetcode.com/problems/maximum-width-ramp/description/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size = nums.size();
        vector<int> maxRightFromIndex(size);
        
        maxRightFromIndex[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRightFromIndex[i] = max(maxRightFromIndex[i + 1], nums[i]);
        }

        int maxRampWidth = 0;
        int leftIndex = 0;
        int rightIndex = 0;

        while (rightIndex < size) {
            while (leftIndex < rightIndex && nums[leftIndex] > maxRightFromIndex[rightIndex]) {
                leftIndex++;
            }

            maxRampWidth = max(maxRampWidth, rightIndex - leftIndex);
            rightIndex++;
        }

        return maxRampWidth;
    }
};



