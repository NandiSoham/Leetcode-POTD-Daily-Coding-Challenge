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

//--------------------------------------------------------------------------
