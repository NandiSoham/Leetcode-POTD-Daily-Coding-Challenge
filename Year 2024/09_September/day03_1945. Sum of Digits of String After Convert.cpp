// Problem Link -> https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

// ------------------------------ Approach - 1 -----------------------------

class Solution {
public:
    int getLucky(string s, int k) {
        int currentSum = 0;

        for (auto ch : s) {
            int charValue = ch - 'a' + 1;
            while (charValue > 0) {
                currentSum += charValue % 10;
                charValue /= 10;
            }
        }

        for (int i = 1; i < k; i++) {
            int newSum = 0;
            while (currentSum > 0) {
                newSum += currentSum % 10;
                currentSum /= 10;
            }
            currentSum = newSum;
        }

        return currentSum;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// -------------------------------------------------------------------------


// ------------------------------ Approach - 2 -----------------------------

class Solution {
public:
    int getLucky(string s, int k) {
        string numericString = "";

        for(auto ch: s){
            int charNumericVal = ch - 'a' + 1;
            numericString += to_string(charNumericVal);
        }

        int digitSum = 0;
        while(k--){
            digitSum = 0;
            for(char ch : numericString){
                digitSum += ch - '0';
            }

            numericString = to_string(digitSum);
        }

        return stoi(numericString);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// -------------------------------------------------------------------------
