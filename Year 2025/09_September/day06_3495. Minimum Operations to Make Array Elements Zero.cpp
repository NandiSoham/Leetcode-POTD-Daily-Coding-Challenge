// problem Link -> https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/

class Solution {
public:

    long long countStepsInRange(int leftBound, int rightBound) {
        long long start = 1;         
        long long weight = 1;        
        long long stepSum = 0;   

        while (start <= rightBound) {
            long long end = 4 * start - 1;  

            long long segStart = max((long long)leftBound, start);
            long long segEnd   = min((long long)rightBound, end);

            if (segStart <= segEnd) {
                stepSum += (segEnd - segStart + 1) * weight;
            }

            weight++;        
            start *= 4;     
        }

        return stepSum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long totalOps = 0;

        for (auto &q : queries) {
            int leftBound = q[0];
            int rightBound = q[1];

            long long stepsHere = countStepsInRange(leftBound, rightBound);
            totalOps += (stepsHere + 1) / 2;   
        }

        return totalOps;
    }
};




// Time Complexity -> O(Q × log₄(rightBound))
// Space Complexity -> O(1)
