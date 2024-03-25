Problem Link -> https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// ------------------------- Approach - 1 -> Using unordered map (Brute Force) ----------------------------

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

// --------------------------------------------------------------------------------------------------

// ------------------------- Approach - 2 -> Using Sorting (Brute Force) ----------------------------

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};


// Time Complexity -> O(n long)
// Space Complexity -> O(1)

// --------------------------------------------------------------------------------------------------

// --------------------------------- Approach - 2  (Optimal Approach) -------------------------------

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int number = abs(nums[i]);
            int idx = number - 1;

            if(nums[idx] < 0){
                ans.push_back(number);
            } else{
                nums[idx] *= -1;
            }
        }
        return ans;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

--------------------------------------------------------------------------------------------------
