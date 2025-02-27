// Problem Link -> https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int max_length = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp);
                if (length >= 3) {
                    max_length = max(max_length, length);
                }
            }
        }
        return max_length >= 3 ? max_length : 0;
    }
    
private:
    int solve(int j, int k, const vector<int>& arr, const unordered_map<int, int>& mp) {
        int target = arr[k] - arr[j];
        if (mp.count(target) && mp.at(target) < j) {
            int i = mp.at(target);
            return solve(i, j, arr, mp) + 1;
        }
        return 2;
    }
};


// Time Complexity ->O(n^2)
// Space Complexity -> O(n^2)

// =========================================================================================
