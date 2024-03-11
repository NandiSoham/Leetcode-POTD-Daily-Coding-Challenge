// Problem Link -> https://leetcode.com/problems/intersection-of-two-arrays/description/

//--------------------------------- Approach - 1 (Using two set) ------------------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2;

        for(int &it : nums2){
            if(set1.find(it) != set1.end()){
                set2.insert(it);
            }
        }

        vector<int> uniqueElementArray(set2.begin(), set2.end());
        return uniqueElementArray;
    }
};


// Time Complexity -> O(n + m)
// Space Complexity -> O(n + m)

//---------------------------------------------------------------------------------------------

//--------------------------------- Optimised Approach - 1 (Using one set) --------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> uniqueElementArray;
        
        for(int &it : nums2){
            if(set1.find(it) != set1.end()){
                uniqueElementArray.push_back(it);
                set1.erase(it);
            }
        }

        return uniqueElementArray;
    }
};


// Time Complexity -> O(n + m)
// Space Complexity -> O(n + m)

//---------------------------------------------------------------------------------------------

//--------------------------------- Approach -2 (Using Two Pointers) --------------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ptr1 = 0, ptr2 = 0;
        vector<int> intersectionArr;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while(ptr1 < n && ptr2 < m){
            if(nums1[ptr1] == nums2[ptr2]){
                intersectionArr.push_back(nums1[ptr1]);

                while(ptr1 < n-1 && nums1[ptr1] == nums1[ptr1 + 1]) ptr1++;
                while(ptr2 < m-1 && nums2[ptr2] == nums2[ptr2 + 1]) ptr2++;
                ptr1++, ptr2++;
            } else if(nums1[ptr1] < nums2[ptr2]) ptr1++;
            else ptr2++;
        }
        return intersectionArr;
    }
};


// Time Coplexity -> O(n + m)
// Space Complexity -> O(1)

//---------------------------------------------------------------------------------------------

//--------------------------------- Approach - 3 (Binary Search) --------------------------

class Solution {
public:
    
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        
        unordered_set<int> st;
        
        for(int &num : nums2) {
            if(binarySearch(nums1, num)) {
                st.insert(num);
            }
        }
        
        vector<int> result(begin(st), end(st));
        
        return result;
        
    }
};


//Time Complexity -> O(n + mlogm)
//Space Complexity -> O(n)

//---------------------------------------------------------------------------------------------
