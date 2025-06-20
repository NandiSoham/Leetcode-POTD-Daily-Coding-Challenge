// Problem Link -> https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDistReached = 0;

        int northCount = 0;
        int southCount = 0;
        int eastCount = 0;
        int westCount = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'N') northCount++;
            else if(s[i] == 'S') southCount++;
            else if(s[i] == 'E') eastCount++;
            else if(s[i] == 'W') westCount++;

            int currManDist = abs(northCount - southCount) + abs(eastCount - westCount);

            int currStepCount = i + 1;
            int wastedSteps = currStepCount - currManDist;
            
            int bonusSteps = 0;
            if(wastedSteps != 0){
                bonusSteps = min(wastedSteps, 2 * k);
            }

            int finalDist = currManDist + bonusSteps;
            maxDistReached = max(maxDistReached, finalDist);
        }

        return maxDistReached;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)
