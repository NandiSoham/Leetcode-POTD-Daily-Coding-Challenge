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

// -------------------------------- Approach - 2 -----------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottleCount = numBottles;
        int emptyBottleCount = numBottles;

        while(emptyBottleCount >= numExchange){
            int exchnagedBottleCount = emptyBottleCount / numExchange;
            int remainingBottleCount = emptyBottleCount % numExchange;

            consumedBottleCount += exchnagedBottleCount;
            emptyBottleCount = remainingBottleCount + exchnagedBottleCount;
        }

        return consumedBottleCount;
    }
};

// ---------------------------------------------------------------------------

// -------------------------------- Approach - 3 -----------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

// ---------------------------------------------------------------------------
