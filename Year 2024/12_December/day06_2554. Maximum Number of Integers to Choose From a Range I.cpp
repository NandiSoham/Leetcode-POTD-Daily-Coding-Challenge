// Problem Link -> https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int currSum = 0;
        int countInt = 0;

        for(int num = 1; num <= n; num++){
            if(bannedSet.count(num)) continue;

            if(currSum + num <= maxSum){
                countInt++;
                currSum += num;
            } else break;
        }

        return countInt;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
