// Problem Link -> https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

// ---------------------------------------- Approach - 1 (Using Sorting) ---------------------------------------

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        int childrenCount = 0;
        long long happinessSum = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int i = 0; i < k; i++){
            happinessSum += max(0, (happiness[i] - childrenCount));
            childrenCount++;
        }
        return happinessSum;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(1)

//--------------------------------------------------------------------------------------------------------------
