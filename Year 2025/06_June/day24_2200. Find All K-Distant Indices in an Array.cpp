// Problem Link -> https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int> ansArr;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(i - k, 0);
                int end = min(i + k, n - 1);

                if (!ansArr.empty() && ansArr.back() >= start) {
                    start = ansArr.back() + 1;
                }

                for (int idx = start; idx <= end; idx++) {
                    ansArr.push_back(idx);
                }
            }
        }

        return ansArr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
