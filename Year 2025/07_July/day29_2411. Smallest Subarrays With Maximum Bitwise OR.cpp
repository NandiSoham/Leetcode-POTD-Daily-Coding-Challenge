// Problem link -> https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> bitReach(32, -1);

        for (int i = n - 1; i >= 0; --i) {
            int maxReach = i;

            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    bitReach[bit] = i;
                } else if (bitReach[bit] != -1) {
                    maxReach = max(maxReach, bitReach[bit]);
                }
            }

            result[i] = maxReach - i + 1;
        }

        return result;
    }
};



// time COmplexity -> O(n)
// space complexity -> O(1)
