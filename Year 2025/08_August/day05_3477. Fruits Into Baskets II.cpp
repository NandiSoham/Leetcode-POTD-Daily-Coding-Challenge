// Problem Link -> https://leetcode.com/problems/fruits-into-baskets-ii/description/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int placedCount = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j]){
                    placedCount++;
                    baskets[j] = -1;
                    break;
                }
            }
        }

        return n - placedCount;
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)
