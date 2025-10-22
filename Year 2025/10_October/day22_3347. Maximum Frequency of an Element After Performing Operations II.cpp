// problm link -> https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int maxOps) {
        int limit = *max_element(nums.begin(), nums.end()) + k;
        map<int, int> impact;
        unordered_map<int, int> seen;

        for (int val : nums) {
            seen[val]++;

            int leftBound = max(0, val - k);
            int rightBound = min(limit, val + k);

            impact[leftBound]++;
            impact[rightBound + 1]--;

            impact[val] += 0;
        }

        int best = 1;
        int running = 0;

        for (auto it = impact.begin(); it != impact.end(); ++it) {
            int currVal = it->first;
            it->second += running;

            int existing = seen[currVal];
            int available = it->second - existing;
            int canUpgrade = min(available, maxOps);

            best = max(best, existing + canUpgrade);
            running = it->second;
        }

        return best;
    }
};



// Time Complexity -> O(n log n)
// Space Complexity -> O(n)
