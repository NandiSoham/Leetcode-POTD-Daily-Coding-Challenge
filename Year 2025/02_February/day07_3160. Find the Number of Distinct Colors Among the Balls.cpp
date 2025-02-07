// Problem Link -> https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

// ======================================= Approach - 1 (MLE) ====================================

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ansArr(n);
        vector<int> ballColor(limit+1, -1);
        unordered_map<int, int> colorFreqMap;

        for(int i = 0; i < n; i++){
            int currBall = queries[i][0];
            int currColor = queries[i][1];

            if(ballColor[currBall] != -1){ // this means ball is already colored
                int prevColor = ballColor[currBall];
                colorFreqMap[prevColor]--;

                if(colorFreqMap[prevColor] == 0){
                    colorFreqMap.erase(prevColor);
                }
            }

            ballColor[currBall] = currColor;   // when ball is not colored
            colorFreqMap[currColor]++;
            
            ansArr[i] = colorFreqMap.size(); 
        }

        return ansArr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(limit)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ansArr(n);
        unordered_map<int, int> ballColorMap;
        unordered_map<int, int> colorFreqMap;

        for(int i = 0; i < n; i++){
            int currBall = queries[i][0];
            int currColor = queries[i][1];

            if(ballColorMap.count(currBall)){ // this means ball is already colored
                int prevColor = ballColorMap[currBall];
                colorFreqMap[prevColor]--;

                if(colorFreqMap[prevColor] == 0){
                    colorFreqMap.erase(prevColor);
                }
            }

            ballColorMap[currBall] = currColor;   // when ball is not colored
            colorFreqMap[currColor]++;
            
            ansArr[i] = colorFreqMap.size(); 
        }

        return ansArr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =========================================================================================
