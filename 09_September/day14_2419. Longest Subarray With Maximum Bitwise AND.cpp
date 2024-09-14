// Problem Link -> https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0;
        int longestStreak = 0; 
        int currentStreak = 0; 

        for (int num : nums) {
            if (num > maxElement) { 
                maxElement = num;
                longestStreak = 0;
                currentStreak = 0;
            }

            if (maxElement == num) { 
                currentStreak++;
            } else {
                currentStreak = 0; 
            }

            longestStreak = max(longestStreak, currentStreak); 
        }

        return longestStreak;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
