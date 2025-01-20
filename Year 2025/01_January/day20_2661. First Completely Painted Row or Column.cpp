// Problem Link -> https://leetcode.com/problems/first-completely-painted-row-or-column/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        unordered_map<int, pair<int, int>> coordinateMap;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int val = mat[i][j];
                coordinateMap[val] = {i, j};
            }
        }

        vector<int> paintedRowCount(r, 0);
        vector<int> paintedColCount (c, 0);

        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            auto [row, col] = coordinateMap[val];

            paintedRowCount[row]++;
            paintedColCount[col]++;

            if(paintedRowCount[row] == c || paintedColCount[col] == r){
                return i;
            }
        }
        
        return -1;
    }
};



// Time Complexity: O((m*n) * s*(m+n)) , s = size of arr
// Space Complexity: O(m*n)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        unordered_map<int, pair<int, int>> coordinateMap;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int val = mat[i][j];
                coordinateMap[val] = {i, j};
            }
        }

        vector<int> paintedRowCount(r, 0);
        vector<int> paintedColCount (c, 0);

        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            auto [row, col] = coordinateMap[val];

            paintedRowCount[row]++;
            paintedColCount[col]++;

            if(paintedRowCount[row] == c || paintedColCount[col] == r){
                return i;
            }
        }
        
        return -1;
    }
};



// Time Complexity: O (r * c)
// Space Complexity: O((r*c) + r + c)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        unordered_map<int, int> valIdxMap;

        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            valIdxMap[value] = i;
        }

        int minIdx = INT_MAX;
        for (int row = 0; row < r; row++) {
            int maxIndexInRow = INT_MIN; 

            for (int col = 0; col < c; col++) {
                int value = mat[row][col];
                int index = valIdxMap[value];
                maxIndexInRow = max(maxIndexInRow, index);
            }
            minIdx = min(minIdx, maxIndexInRow);
        }

        for (int col = 0; col < c; col++) {
            int maxIndexInCol = INT_MIN; 

            for (int row = 0; row < r; row++) {
                int value = mat[row][col];
                int index = valIdxMap[value];
                maxIndexInCol = max(maxIndexInCol, index);
            }
            minIdx = min(minIdx, maxIndexInCol);
        }

        return minIdx;
    }
};



// Time Complexity: O (r * c)
// Space Complexity: O (r * c)
