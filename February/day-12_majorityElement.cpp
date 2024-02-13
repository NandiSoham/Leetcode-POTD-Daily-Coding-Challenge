class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            } else if(element == nums[i]) count += 1;
            else count -= 1;
        }

        int count1 = 0;
        for(int i = 0; i <nums.size(); i++){
            if(nums[i] == element) count1 += 1;
        }

        if(count1 > nums.size()/2) return element;
        else return -1;

    }
};


// Time Complity -> O(N)
// Space Complexity ->v
//Problem Link -> https://leetcode.com/problems/majority-element/description/
