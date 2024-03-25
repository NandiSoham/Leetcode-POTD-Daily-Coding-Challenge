Problem Link -> https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// ------------------------- Approach - 1 -> Using unordered map----------------------------

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> duplicateElement;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for (auto& it : mpp) {
            if (it.second > 1) {
                duplicateElement.push_back(it.first);
            }
        }

        return duplicateElement;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// -----------------------------------------------------------------------------------------
