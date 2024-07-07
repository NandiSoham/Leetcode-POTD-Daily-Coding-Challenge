// Problem Link -> https://leetcode.com/problems/water-bottles/description/

// -------------------------------- Approach - 1 -----------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottleCount = 0;

        while(numBottles >= numExchange){
            consumedBottleCount += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }

        return consumedBottleCount + numBottles;
    }
};

// ---------------------------------------------------------------------------
