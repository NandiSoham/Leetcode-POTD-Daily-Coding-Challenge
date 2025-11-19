// Problem Link -> https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int arr[1001] = {0};

        for(int &num : nums) {
            arr[num]++;
        }

        while(original <= 1000 && arr[original] != 0) {
            original *= 2;
        }

        return original;
    }
};


// Time Com[plexity -> O(n)
// Space Complexity -> O(1)
