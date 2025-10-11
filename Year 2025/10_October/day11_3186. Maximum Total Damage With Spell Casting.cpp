// Problem Link -> https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

class Solution {
public:
    typedef long long ll;
    int n;                                
    unordered_map<ll,ll> freq;      
    vector<ll> dp;           

    ll solve(int i, const vector<ll>& nums) {
        if (i >= n) return 0;  

        if (dp[i] != -1) return dp[i];  

        ll skip = solve(i + 1, nums);

        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * freq[nums[i]] + solve(j, nums);

        return dp[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (int x : power) 
            freq[x]++;

        vector<ll> nums;
        nums.reserve(freq.size());
        for (auto &p : freq)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));
        n = nums.size();
        dp.assign(n, -1);

        return solve(0, nums);
    }
};


// time Complexity -> O(n log n)
// Space Complexity -> O(n)
