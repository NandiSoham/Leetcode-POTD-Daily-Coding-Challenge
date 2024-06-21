// Problem Link -> https://leetcode.com/problems/grumpy-bookstore-owner/description/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int curr_unsatisfied = 0;
        int max_unsatisfied = 0;

        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1) curr_unsatisfied += customers[i];
        }
        max_unsatisfied = curr_unsatisfied;

        int i = 0, j = minutes;
        while(j < n){
            curr_unsatisfied += customers[j] * grumpy[j];
            curr_unsatisfied -= customers[i] * grumpy[i];
            max_unsatisfied = max(max_unsatisfied, curr_unsatisfied);
            i++, j++;
        }

        int total_satisfied = max_unsatisfied;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0) total_satisfied += customers[i];
        }

        return total_satisfied;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
