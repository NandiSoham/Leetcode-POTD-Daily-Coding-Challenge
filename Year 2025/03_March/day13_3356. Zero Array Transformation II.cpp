// Problem Link -> https://leetcode.com/problems/zero-array-transformation-ii/description/

class Solution {
public:
    int n;
    int queryCount;

    bool isValidWithDifferenceArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        for(int i = 0; i <= k; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            diff[left] += val;
            if(right + 1 < n)
                diff[right + 1] -= val;
        }

        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        queryCount = queries.size();

        auto isZero = [](int val) {
            return val == 0;
        };

        if(all_of(begin(nums), end(nums), isZero)) {
            return 0;
        }

        int left = 0;
        int right = queryCount - 1;
        int result = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(isValidWithDifferenceArray(nums, queries, mid) == true) {
                result = mid + 1;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};


// Time Complexity -> O((k+n)⋅logqueryCount)
// Space Complexity -> O(n)
