// Problem link -> https://leetcode.com/problems/water-bottles-ii/description/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            empty -= numExchange;
            drank += 1;
            empty++;
            numExchange++;
        }

        return drank;
    }
};


// Time Complexity ->	O(√n)
// Space Complexity ->	O(1)
