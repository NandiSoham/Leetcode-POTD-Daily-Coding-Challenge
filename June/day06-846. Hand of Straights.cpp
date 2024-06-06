// Problem Link -> https://leetcode.com/problems/hand-of-straights/description/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> freqMap;
        for(auto it : hand){
            freqMap[it]++;
        }

        while(!freqMap.empty()){
            int currElement = freqMap.begin()->first;

            for(int i = 0; i < groupSize; i++){
                if(freqMap[currElement + i] == 0) return false;

                freqMap[currElement + i]--;
                if(freqMap[currElement + i] < 1)
                    freqMap.erase(currElement + i);
            }
        }
        return true;
    }
};



// Time Complexity -> O(nlogn) + O(n*groupSize)
// Space Complexity -> O(n)
