// Problem Link -> https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

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
