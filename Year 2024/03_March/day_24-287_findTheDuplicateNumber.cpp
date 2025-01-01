// Problem Link -> https://leetcode.com/problems/find-the-duplicate-number/

// ------------------- Approach 1 -> Implemented Tortoise and Hare Algorithm -------------------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------------------

// ---------------------------- Approach - 2 -> Sort and search iteratively --------------------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int prev = -1;
        for (int num : nums) {
            if (num == prev)
                break;
            prev = num;
        }

        return prev;
        }
};



// Time Complexity -> O(n long)
// Space Complexity -> O(1)
// ---------------------------------------------------------------------------------------------------
