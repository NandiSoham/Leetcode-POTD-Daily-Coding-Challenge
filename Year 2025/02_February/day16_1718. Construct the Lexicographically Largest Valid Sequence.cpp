// Problem Link -> https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

class Solution {
public:
    bool generateValidSequence(int idx, int n, vector <int>& ansArr, vector <bool>& isUsed){
        if(idx >= ansArr.size()) return true;

        if(ansArr[idx] != -1){
            return generateValidSequence(idx + 1, n, ansArr, isUsed);
        }

        for(int num = n; num >= 1; num--){
            if(isUsed[num] == true) continue;

            // Step 1: try placing the number
            ansArr[idx] = num;
            isUsed[num] = true;

            // Step2: Explore the option
            if(num == 1){
                if(generateValidSequence(idx + 1, n, ansArr, isUsed) == true){
                    return true;
                }
            } else {
                int nextIdx = idx + ansArr[idx];
                if(nextIdx < ansArr.size() && ansArr[nextIdx] == -1){
                    ansArr[nextIdx] = num;
                    if(generateValidSequence(idx + 1, n, ansArr, isUsed) == true){
                        return true;
                    }
                    ansArr[nextIdx] = -1;
                }
            }

            // Step 3: Undo the chosen option
            ansArr[idx] = -1;
            isUsed[num] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector <int> ansArr(2*n - 1, -1);
        vector <bool> isUsed (n + 1, false);

        generateValidSequence(0, n, ansArr, isUsed);
        return ansArr;
    }
};



// Time Complexity -> O(n!)
// Space Complexity -> O(n)
