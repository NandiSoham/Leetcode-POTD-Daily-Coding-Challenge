// Problem Link -> https://leetcode.com/problems/make-sum-divisible-by-p/description/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalMod = 0;

        for (int x : nums) {
            totalMod = (totalMod + x) % p;
        }

        int need = totalMod % p;
        if (need == 0) return 0;   

        unordered_map<int, int> lastSeen;  
        lastSeen[0] = -1;          

        long long prefix = 0;
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            int required = (prefix - need + p) % p;

            if (lastSeen.count(required)) {
                ans = min(ans, i - lastSeen[required]);
            }

            lastSeen[prefix] = i;
        }

        return (ans == n ? -1 : ans);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
