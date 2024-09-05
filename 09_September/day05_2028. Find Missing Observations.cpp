// Problem link -> https://leetcode.com/problems/find-missing-observations/description/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0; 

        for(auto it : rolls){
            sum += it;
        }

        int remainingSum = mean * (n + m) - sum;

        if(remainingSum < 1 * n || remainingSum > 6 * n)
            return {};

        int d = remainingSum / n;
        int rem = remainingSum % n;
        vector<int> ansArr(n, d);

        for(int i = 0; i < rem; i++){
            ansArr[i]++;
        }

        return ansArr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
