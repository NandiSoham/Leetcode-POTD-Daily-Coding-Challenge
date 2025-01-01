// Problem Link -> https://leetcode.com/problems/different-ways-to-add-parentheses/description/

class Solution {
public:
    vector<int> evaluateExpression(string expression) {
        vector<int> results;

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftResults  = evaluateExpression(expression.substr(0, i));
                vector<int> rightResults = evaluateExpression(expression.substr(i + 1));

                for (int &left : leftResults) {
                    for (int &right : rightResults) {
                        if (expression[i] == '+') {
                            results.push_back(left + right);
                        } else if (expression[i] == '-') {
                            results.push_back(left - right);
                        } else {
                            results.push_back(left * right);
                        }
                    }
                }
            }
        }

        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        return results;
    }

    vector<int> diffWaysToCompute(string expression) {
        return evaluateExpression(expression);
    }
};



//Time Complexity -> O(n*2^n)
//Space Complexity -> O(2^n)
