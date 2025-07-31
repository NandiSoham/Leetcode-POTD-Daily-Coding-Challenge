// Problem Link -> https://leetcode.com/problems/bitwise-ors-of-subarrays/description/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> previousSet;
        unordered_set<int> currentSet;
        unordered_set<int> uniqueResults;

        for (int i = 0; i < arr.size(); ++i) {
            for (const int& value : previousSet) {
                currentSet.insert(value | arr[i]);
                uniqueResults.insert(value | arr[i]);
            }

            currentSet.insert(arr[i]);
            uniqueResults.insert(arr[i]);

            previousSet = move(currentSet);
            currentSet.clear();
        }

        return uniqueResults.size();
    }
};



// Time Complexity -> O(n*32) ~ O(n)
// Space Complexity -> O(n*32) ~ O(n)
