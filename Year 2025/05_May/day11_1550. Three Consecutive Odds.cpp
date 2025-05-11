// Problem Link -> https://leetcode.com/problems/three-consecutive-odds/description/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int consecutiveOddCount = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                consecutiveOddCount++;
            } else {
                consecutiveOddCount = 0;
            }

            if(consecutiveOddCount == 3)
                return true;
        }
        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
