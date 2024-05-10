// Problem Link -> https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

// ---------------------------------------- Approach - 1 (Using Sorting) ---------------------------------------

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, pair<int, int>>> vec;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double val = arr[i] / (double)arr[j]; 
                vec.push_back({val, {i, j}});
            }
        }

        sort(vec.begin(), vec.end());

        int firstVal = vec[k - 1].second.first;
        int secVal = vec[k - 1].second.second;

        return { arr[firstVal], arr[secVal]};
    }
};



// Time Complexity -> O(n^2 * nlogn)
// Space Complexity -> O(k)

//----------------------------------------------------------------------------------------------------------------
