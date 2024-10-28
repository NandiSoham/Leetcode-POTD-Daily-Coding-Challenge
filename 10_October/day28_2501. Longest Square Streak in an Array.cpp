// Problem Link -> https://leetcode.com/problems/longest-square-streak-in-an-array/description/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int maxStreak = 0;

        for(int &num : nums) {
            int streak = 0;
            long long curr = num;

            while(st.find(curr) != st.end()) {
                streak++;

                if(curr * curr > 1e5) {  
                    break;
                }
                curr = curr * curr; 
            }
            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
