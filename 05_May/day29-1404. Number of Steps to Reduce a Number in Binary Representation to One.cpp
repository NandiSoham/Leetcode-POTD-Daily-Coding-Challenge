// Problem Link -> https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// ------------------------------------------ Approach - 1 --------------------------------------------
class Solution {
public:
    int numSteps(string s) {
        int operationCount = 0;

        while(s.length() > 1){
            if(s.back() == '1'){
                addOne(s);
                operationCount++;
            } else {
                s.pop_back();
                operationCount++;
            }
        }
        return operationCount;
    }

    void addOne(string& s){
        int i = s.length() - 1;

        while(i >= 0 && s[i] == '1'){
            s[i] = '0';
            i--;
        }
        if(i < 0) s = '1' + s;
        else s[i] = '1';
    }
};


// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// ----------------------------------------------------------------------------------------------------

// ------------------------------------------ Approach - 2 --------------------------------------------

class Solution {
public:
    int numSteps(string s) {
        int operationCount = 0;
        int carry = 0;

        for(int i = s.length() - 1; i >= 1; i--) {
            if(((s[i] - '0') + carry) % 2 == 1) { //odd
                operationCount += 2;
                carry = 1;
            } else { //even
                operationCount += 1;
            }
        }

        return operationCount + carry;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ----------------------------------------------------------------------------------------------------
