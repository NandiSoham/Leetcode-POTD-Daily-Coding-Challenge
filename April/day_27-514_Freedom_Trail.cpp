class Solution {
public:
    int memoization[101][101];

    int stepsCalculation(int ringIndex, int currCharIdx, int n){
        int straightDist = abs(currCharIdx - ringIndex);
        int roundAboutDist = (n - straightDist);
        return min(straightDist, roundAboutDist);
    }

    int search(int ringIndex, int keyIndex, string& ring, string& key){
        int ans = INT_MAX;
        if(keyIndex >= key.length()) return 0;

        if(memoization[ringIndex][keyIndex] != -1){
            return memoization[ringIndex][keyIndex];
        }

        for(int currCharIdx = 0; currCharIdx < ring.length(); currCharIdx++){
            if(ring[currCharIdx] == key[keyIndex]){
                int stepsSum = 1 + stepsCalculation(ringIndex, currCharIdx, ring.length()) +
                                search(currCharIdx, keyIndex + 1, ring, key);
                
                ans  = min(ans, stepsSum);
            }
        }
        return memoization[ringIndex][keyIndex] = ans;
    }

    int findRotateSteps(string ring, string key) {
        memset(memoization, -1, sizeof(memoization));
        return search(0, 0, ring, key);
    }
};    



// Time Complexity -> O(m * (n^2))
// Space Complexity -> O(m * n)
// Problem Link -> https://leetcode.com/problems/freedom-trail/description/
