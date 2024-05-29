// Problem Link -> https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

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
