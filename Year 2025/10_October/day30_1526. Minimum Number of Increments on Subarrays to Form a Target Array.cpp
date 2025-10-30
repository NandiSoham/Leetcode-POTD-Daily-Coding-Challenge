// Problem Link -> https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int operations = target[0];  

        for(int i = 0; i < n - 1; i++){
            if(target[i + 1] > target[i]){
                operations += target[i + 1] - target[i];
            }
        }

        return operations;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
