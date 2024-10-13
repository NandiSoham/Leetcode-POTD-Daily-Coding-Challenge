// Problem Link -> https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int numLists = nums.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int currentMax = INT_MIN;
        for(int i = 0; i < numLists; i++) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000}; 

        while(!minHeap.empty()) {
            vector<int> currentElement = minHeap.top();
            minHeap.pop();

            int currentMin = currentElement[0];
            int listIndex = currentElement[1];
            int elementIndex = currentElement[2];

            if(currentMax - currentMin < resultRange[1] - resultRange[0]) {
                resultRange[0] = currentMin;
                resultRange[1] = currentMax;
            }

            if(elementIndex + 1 < nums[listIndex].size()) {
                int nextElement = nums[listIndex][elementIndex + 1];
                minHeap.push({nextElement, listIndex, elementIndex + 1});
                currentMax = max(currentMax, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};
