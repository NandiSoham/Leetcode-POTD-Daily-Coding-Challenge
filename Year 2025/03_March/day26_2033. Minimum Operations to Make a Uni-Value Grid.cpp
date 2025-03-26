// problem Link -> https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int stepSize) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        vector<int> elements;
        
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                elements.push_back(grid[i][j]);
            }
        }

        int totalElements = elements.size();

        nth_element(elements.begin(), elements.begin() + totalElements / 2, elements.end());

        int medianVal = elements[totalElements / 2];
        int operationsCount = 0;

        for(int &num : elements) {
            if(num % stepSize != medianVal % stepSize) {
                return -1;
            }
            operationsCount += abs(medianVal - num) / stepSize;
        }

        return operationsCount;
    }
};


// Time Complexity -> O(m * n log(m*n))
// Space Complexity -> O(m * n)
