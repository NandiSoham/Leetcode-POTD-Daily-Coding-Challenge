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
