// Problem Link -> https://leetcode.com/problems/average-waiting-time/description/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalWaitTime = 0;
        int chefFreeTime = 0;

        for(auto & it : customers){
            int arrivalTime = it[0];
            int cookTime = it[1];

            if(chefFreeTime < arrivalTime) chefFreeTime = arrivalTime;
            int waitTime = (chefFreeTime + cookTime) - arrivalTime;
            totalWaitTime += waitTime;
            chefFreeTime += cookTime;
        }

        return totalWaitTime / n;
    }
};



// Time Complexity - > O(n)
// Space Complexity -> O(1)
