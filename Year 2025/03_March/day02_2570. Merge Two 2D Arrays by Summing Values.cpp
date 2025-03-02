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


// Time Complexity -> O ((n1 + n2) log(K logK)) [where K  = n1 + n2]
// Space Complexity -> O (n1 + n2)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        map<int, int> valMap;
        vector<vector<int>> ans;

        for(int i = 0; i < n1; i++){
            int key = nums1[i][0];
            int val = nums1[i][1];

            valMap[key] += val;
        }

        for(int i = 0; i < n2; i++){
            int key = nums2[i][0];
            int val = nums2[i][1];

            valMap[key] += val;
        }

        for(auto &element : valMap){
            int key = element.first;
            int val = element.second;

            ans.push_back({key, val});
        }

        return ans;
    }
};


// Time Complexity -> O ((n1 + n2) log(K logK)) [where K  = n1 + n2]
// Space Complexity -> O (n1 + n2)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int index1 = 0;
        int index2 = 0;
        vector<vector<int>> mergedResult;
        
        while (index1 < n1 && index2 < n2) {
            if (nums1[index1][0] < nums2[index2][0]) {
                mergedResult.push_back(nums1[index1]);
                index1++;
            } else if (nums2[index2][0] < nums1[index1][0]) {
                mergedResult.push_back(nums2[index2]);
                index2++;
            } else {
                mergedResult.push_back({nums1[index1][0], nums1[index1][1] + nums2[index2][1]});
                index1++;
                index2++;
            }
        }

        while (index1 < n1) {
            mergedResult.push_back(nums1[index1]);
            index1++;
        }

        while (index2 < n2) {
            mergedResult.push_back(nums2[index2]);
            index2++;
        }
        
        return mergedResult;
    }
};


// Time Complexity -> O (n1 + n2)
// Space Complexity -> O (n1 + n2)

// =========================================================================================
