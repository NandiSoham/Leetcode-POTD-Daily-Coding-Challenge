class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long total = 0;
        
        for (int val : nums) {
            total += val;
        }

        return total % k;
    }
};


// Time complexity -> O(n)
// Space complexity -> O(1)
