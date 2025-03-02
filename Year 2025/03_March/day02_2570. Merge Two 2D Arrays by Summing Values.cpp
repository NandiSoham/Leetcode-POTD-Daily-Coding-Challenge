// Problem Link -> https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> valueMap;
        vector<vector<int>> mergedResult;

        for (int i = 0; i < n1; i++) {
            int key = nums1[i][0];
            int value = nums1[i][1];

            valueMap[key] += value;
        }

        for (int i = 0; i < n2; i++) {
            int key = nums2[i][0];
            int value = nums2[i][1];

            valueMap[key] += value;
        }

        for (auto &entry : valueMap) {
            int key = entry.first;
            int value = entry.second;

            mergedResult.push_back({key, value});
        }

        sort(begin(mergedResult), end(mergedResult));

        return mergedResult;
    }
};


// Time Complexity -> O ((n1 + n2) log(n1+n2))
// Space Complexity -> O (n1 + n2)

// =========================================================================================
