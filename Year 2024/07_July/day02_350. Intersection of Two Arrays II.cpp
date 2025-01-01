// Problem Link -> https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// ---------------------------------- Approach - 1 -------------------------------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freqMap;
        for(int &num : nums1){
            freqMap[num]++;
        }

        vector<int> ans;
        for(int  i = 0; i < nums2.size(); i++){
            int num = nums2[i];
            if(freqMap[num] > 0){
                ans.push_back(num);
                freqMap[num]--;
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// -------------------------------------------------------------------------------

// ---------------------------------- Approach - 2 -------------------------------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ptr1 = 0, ptr2 = 0;
        vector<int> ans;

        while(ptr1 < nums1.size() && ptr2 < nums2.size()){
            if(nums1[ptr1] == nums2[ptr2]){
                ans.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            } else if(nums1[ptr1] < nums2[ptr2]){
                ptr1++;
            } else ptr2++;
        }

        return ans;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

// -------------------------------------------------------------------------------
