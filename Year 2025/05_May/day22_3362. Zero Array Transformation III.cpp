// Problem Link -> https://leetcode.com/problems/zero-array-transformation-iii/description/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> usedQueryEnds;
        priority_queue<int> availableQueryEnds;

        sort(queries.begin(), queries.end());

        int queryIdx = 0;
        int totalUsedQueries = 0;

        for (int i = 0; i < n; ++i) {
            while (queryIdx < queries.size() && queries[queryIdx][0] == i) {
                availableQueryEnds.push(queries[queryIdx][1]);
                ++queryIdx;
            }

            nums[i] -= usedQueryEnds.size();

            while (nums[i] > 0 && !availableQueryEnds.empty() && availableQueryEnds.top() >= i) {
                int endIndex = availableQueryEnds.top(); availableQueryEnds.pop();
                usedQueryEnds.push(endIndex);
                totalUsedQueries++;
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;

            while (!usedQueryEnds.empty() && usedQueryEnds.top() == i) {
                usedQueryEnds.pop();
            }
        }

        return queries.size() - totalUsedQueries;
    }
};


