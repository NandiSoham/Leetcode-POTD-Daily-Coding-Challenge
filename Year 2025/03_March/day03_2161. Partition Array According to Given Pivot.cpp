// Problem Link -> https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smallerElements;
        vector<int> equalElements;
        vector<int> largerElements;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) smallerElements.push_back(nums[i]);
            else if (nums[i] == pivot) equalElements.push_back(nums[i]);
            else largerElements.push_back(nums[i]);
        }

        for(int i = 0; i < equalElements.size(); i++){
            smallerElements.push_back(equalElements[i]);
        }

        for(int i = 0; i < largerElements.size(); i++){
            smallerElements.push_back(largerElements[i]);
        }

        return smallerElements;
    }
};


// Time Complexity -> O (n)
// Space Complexity -> O (n)

// =========================================================================================


// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int countSmaller = 0;
        int countEqual = 0;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) countSmaller++;
            else if (nums[i] == pivot) countEqual++;
        }

        int smallerIdx = 0;
        int equalIdx = countSmaller;
        int largerIdx = countSmaller + countEqual;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                ans[smallerIdx] = nums[i];
                smallerIdx++;
            } else if (nums[i] == pivot){
                ans[equalIdx] = nums[i];
                equalIdx++;
            } else {
                ans[largerIdx] = nums[i];
                largerIdx++;
            }
        }

        return ans;
    }
};


// Time Complexity -> O (n)
// Space Complexity -> O (1)

// =========================================================================================
