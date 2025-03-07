// Problem Link -> https://leetcode.com/problems/find-missing-and-repeated-values/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalElements = n * n;
        unordered_map<int, int> freqMap;

        int repeatedVal = -1;
        int missingVal = -1;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                freqMap[grid[row][col]]++;
            }
        }

        for(int num = 1; num <= totalElements; num++){
            if(!freqMap.count(num)){
                missingVal = num;
            } else if (freqMap[num] == 2){
                repeatedVal = num;
            }

            if(repeatedVal != -1 && missingVal != -1){
                break;
            }
        }

        return {repeatedVal, missingVal};
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(n^2)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long totalElements = n * n;
        long long actualSum = 0;
        long long actualSquareSum = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                actualSum += grid[row][col];
                actualSquareSum += grid[row][col] * grid[row][col];
            }
        }

        long long expectedSum = (totalElements * (totalElements + 1)) / 2;
        long long expectedSquareSum = (totalElements * (totalElements + 1) * (2 * totalElements + 1)) / 6;

        int squareDifference = actualSquareSum - expectedSquareSum;
        int sumDifference = actualSum - expectedSum;

        int repeatedValue = (squareDifference / sumDifference + sumDifference) / 2; 
        int missingValue = (squareDifference / sumDifference - sumDifference) / 2;

        return {repeatedValue, missingValue};
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(1)

// =========================================================================================
