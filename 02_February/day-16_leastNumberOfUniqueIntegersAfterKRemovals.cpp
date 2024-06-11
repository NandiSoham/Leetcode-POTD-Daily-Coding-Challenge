class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        int n = arr.size();
        for(int &x : arr) {
            mpp[x]++;
        }

        vector<int> freqCount(n+1);
        int uniqueElements = mpp.size();

        for(auto &it : mpp){
            int freq = it.second;
            freqCount[freq]++;
        }

        for(int freq = 1; freq <= n; freq++){
            int typesICanDelete = min(k/freq, freqCount[freq]);
            k = k - (typesICanDelete * freq);
            uniqueElements -= typesICanDelete;

            if(k <= freq){
                return uniqueElements;
            }
        }
        return 0;
    }
};


// Time Complexity -> O(N)
// Space Complexity -> O(N)
// Problem Link -> https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
