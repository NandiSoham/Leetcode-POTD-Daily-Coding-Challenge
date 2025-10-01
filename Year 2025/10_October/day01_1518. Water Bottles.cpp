// problem link -> https://leetcode.com/problems/water-bottles/description/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = 0;

        while(numBottles >= numExchange){
            totalDrunk += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }

        return totalDrunk + numBottles;
    }
};


// Time Complexity -> O(log n)
// Space Complexity -> O(1)
