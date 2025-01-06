// Problem Link -> https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                st.insert(i);
            }
        }

        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {
            for(auto &idx : st) {
                answer[i] += abs(i - idx);
            }
        }

        return answer;

    }
};



// Time Complexity: O (n^2)
//Space Complexity: O (1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {

            if(boxes[i] == '1') {
                for(int j = 0; j < n; j++) {
                    answer[j] += abs(j-i);
                }
            }
        }

        return answer;
    }
};



// Time Complexity: O (n^2)
//Space Complexity: O (1)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> resultArr(n, 0);
        int cumVal = 0;
        int cumValSum = 0;

        for(int i = 0; i < n; i++){
            resultArr[i] = cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }

        cumVal = 0;
        cumValSum = 0;

        for(int i = n - 1; i >= 0; i--){
            resultArr[i] += cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }

        return resultArr;
    }
};



// Time Complexity: O (n)
//Space Complexity: O (1)

// =========================================================================================
