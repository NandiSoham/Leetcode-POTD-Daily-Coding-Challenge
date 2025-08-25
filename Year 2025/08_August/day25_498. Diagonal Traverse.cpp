// Problem Link -> https://leetcode.com/problems/diagonal-traverse/description/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> diagonals;
        vector<int> ansArr;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                diagonals[i+j].push_back(mat[i][j]);
            }
        }

        bool reverseOrder = true;
        for(auto &it : diagonals){
            if(reverseOrder){
                reverse(it.second.begin(), it.second.end());
            }

            for(int &num : it.second){
                ansArr.push_back(num);
            }

            reverseOrder = !reverseOrder;
        }

        return ansArr;
    }
};


// Time Complexity -> O(m*n)
// Space Complexity -> O(m*n)
