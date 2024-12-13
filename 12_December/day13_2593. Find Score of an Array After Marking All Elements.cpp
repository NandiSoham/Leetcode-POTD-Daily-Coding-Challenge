// Problem Link -> https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

class Solution {
public:
    #define ElementWithIndex pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isVisited(n, false);

        priority_queue<ElementWithIndex, vector<ElementWithIndex>, greater<ElementWithIndex>> minHeap;
        for (int index = 0; index < n; index++) {
            minHeap.push({nums[index], index});
        }

        long long totalScore = 0;
        while (!minHeap.empty()) {
            ElementWithIndex current = minHeap.top();
            int value = current.first;
            int position = current.second;
            minHeap.pop();

            if (!isVisited[position]) {
                isVisited[position] = true;
                totalScore += value;

                if (position - 1 >= 0 && !isVisited[position - 1]) {
                    isVisited[position - 1] = true;
                }
                if (position + 1 < n && !isVisited[position + 1]) {
                    isVisited[position + 1] = true;
                }
            }
        }

        return totalScore;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
