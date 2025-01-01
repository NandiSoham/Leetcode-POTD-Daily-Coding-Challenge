// Problem Link -> https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:
    bool isPossiblePlacing(vector<int>& position, int midForce, int m) {
        int prevPosition = position[0];
        int ballCount = 1;

        for (int i = 1; i < position.size(); i++) {
            int currPosition = position[i];

            if (currPosition - prevPosition >= midForce) {
                ballCount++;
                prevPosition = currPosition;

                if (ballCount >= m) {
                    return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int resultForce = 0;
        sort(position.begin(), position.end());

        int minForce = 0;
        int maxForce = position.back() - position[0];
        while (minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce) / 2;
            if (isPossiblePlacing(position, midForce, m)) {
                resultForce = midForce;
                minForce = midForce + 1;
            } else {
                maxForce = midForce - 1;
            }
        }
        return resultForce;
    }
};



// Time Complexity -> O(nlogn + n*logx) where x = max force difference
// Space Complexity -> 
