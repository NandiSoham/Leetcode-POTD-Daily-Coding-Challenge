// Problem Link -> https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ansArr(n);

        for(int i = 0; i < n; i++){
            int matchedCount = 0;

            for(int idxA = 0; idxA <= i; idxA++){

                for(int idxB = 0; idxB <= i; idxB++){
                    if(B[idxB] == A[idxA]){
                        matchedCount++;
                        break;
                    }
                }
            }

            ansArr[i] = matchedCount;
        }

        return ansArr;
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
    
        vector<int> commonElements(n);

        vector<bool> seenInA(n + 1, false);
        vector<bool> seenInB(n + 1, false);
        
        for(int position = 0; position < n; position++) {
            int currentNumFromA = A[position];
            int currentNumFromB = B[position];
            
            seenInA[currentNumFromA] = true;
            seenInB[currentNumFromB] = true;
            
            int commonCount = 0;
            for(int number = 1; number <= n; number++) {

                if(seenInA[number] && seenInB[number]) {
                    commonCount++;
                }
            }
            
            commonElements[position] = commonCount;
        }
        
        return commonElements;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// =========================================================================================

