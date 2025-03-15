// Problem Link -> https://leetcode.com/problems/house-robber-iv/description/

// ======================================= Approach - 1 (Brute Force - TLE) ====================================

class Solution {
public:
    int n;
    int findMinCapability(vector<int>& nums, int idx, int remaining, vector<vector<int>>& memo) {
        if(remaining == 0) {
            return 0;
        }

        if(idx >= n) {
            return INT_MAX;
        }   

        if(memo[idx][remaining] != -1) {
            return memo[idx][remaining];
        }

        int take = max(nums[idx], findMinCapability(nums, idx + 2, remaining - 1, memo));

        int skip = findMinCapability(nums, idx + 1, remaining, memo);

        return memo[idx][remaining] = min(take, skip);
    }

    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        return findMinCapability(nums, 0, k, memo);
    }
};

// Time Complexity -> O(n * k)
// Space Complexity -> O(n * k)

// =============================================================================================================


// ================================================ Approach - 2 ================================================

class Solution {
public:
    bool canRobKthHouses(vector<int>& nums, int capacity, int k) {
        int robbedHouses = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= capacity) {
                robbedHouses++;
                i++; 
            }
        }

        return robbedHouses >= k; 
    }
    
    int minCapability(vector<int>& nums, int k) {
        int size = nums.size();

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        int result = right;

        while(left <= right) {
            int mid = left + (right - left) / 2; 

            if(canRobKthHouses(nums, mid, k) == true) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};


// Time Complexity -> O(N∗Log(Max(Nums))
// Space Complexity -> O(1)

// =============================================================================================================
