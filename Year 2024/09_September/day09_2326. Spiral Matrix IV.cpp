// Problem Link -> https://leetcode.com/problems/spiral-matrix-iv/description/

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> resultMatrix (m, vector<int>(n, -1));
        int direction = 0;
        int leftPtr = 0, rightPtr = n - 1, topPtr = 0, downPtr = m - 1;

        while (topPtr <= downPtr && leftPtr <= rightPtr){
            if(direction == 0){
                for(int i = leftPtr; i <= rightPtr  && head != NULL; i++){
                    resultMatrix[topPtr][i] = head -> val;
                    head = head -> next;
                }
                topPtr++;
            }

            if(direction == 1){
                for(int i = topPtr; i <= downPtr  && head != NULL; i++){
                    resultMatrix[i][rightPtr] = head -> val;
                    head = head -> next;
                }
                rightPtr--;
            }

            if(direction == 2){
                for(int i = rightPtr; i >= leftPtr  && head != NULL; i--){
                    resultMatrix[downPtr][i] = head -> val;
                    head = head -> next;
                }
                downPtr--;
            }

            if(direction == 3){
                for(int i = downPtr; i >= topPtr  && head != NULL; i--){
                    resultMatrix[i][leftPtr] = head -> val;
                    head = head -> next;
                }
                leftPtr++;
            }
            direction = (direction + 1) % 4;
        }
        return resultMatrix;
    }
};



// Time Complexity -> O(m * n)
// Space Complexity -> O(1)
