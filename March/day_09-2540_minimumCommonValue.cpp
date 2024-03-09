// Problem Link -> https://leetcode.com/problems/minimum-common-value/

//---------------------------------- APPROACH - 1 ----------------------------

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());

        for(int &it : nums2){
            if(st.find(it) != st.end()) return it;
        }
        return -1;
    }
};



// Time Complexity -> O(n + m)
// Space Complexity -> O(n)

//----------------------------------------------------------------------------

//---------------------------------- APPROACH - 2 ----------------------------

class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int &num : nums1) {
            if(binarySearch(nums2, num))
                return num;
        }
        
        return -1;
    }
};



// Time Complexity -> O(nlogm)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------

//---------------------------------- APPROACH - 3 ----------------------------

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        while(ptr1 < n && ptr2 < m){
            if(nums1[ptr1] == nums2[ptr2]){
                return nums1[ptr1];
            } else if(nums1[ptr1] < nums2[ptr2]) ptr1++;
            else ptr2++;
        }
        return -1;
    }
};



// Time Complexity -> O(n + m)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------
