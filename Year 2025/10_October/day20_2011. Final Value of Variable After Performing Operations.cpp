// Problem Link -> https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        
        for(int i = 0; i < operations.size(); i++){
            
            if(operations[i] == "X++" || operations[i] == "++X"){
                X++;
            } else X--;
        }

        return X;
    }
};


// Time Complexdity -> O(n)
// Space Complexity -> O(1)
