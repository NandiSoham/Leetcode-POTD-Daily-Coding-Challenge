// Problem Link -> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int rotation = 0; rotation < size; rotation++) {
            bool isSorted = true;

            for (int i = 0; i < size; i++) {
                if (sortedNums[i] != nums[(i + rotation) % size]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted) {
                return true;
            }
        }

        return false;
    }
};



// Time Complexity: O (n ^ 2)
// Space Complexity: O (n)

// ===============================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]) count++;
        }

        if(nums[nums.size() - 1] > nums[0])count++;

        return count <= 1;
    }
};



// Time Complexity: O (n)
// Space Complexity: O (1)

// ===============================================================================================
