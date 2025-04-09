// Problem Link -> https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> elementSet;

        for(int &it : nums){
            if(it < k) return -1;
            else if(it > k){
                elementSet.insert(it);
            }
        }

        return elementSet.size();
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
