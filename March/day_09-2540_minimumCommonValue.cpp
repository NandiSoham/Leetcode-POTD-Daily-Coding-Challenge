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

