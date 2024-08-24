// Problem Link -> https://leetcode.com/problems/fraction-addition-and-subtraction/description/https://leetcode.com/problems/fraction-addition-and-subtraction/description/

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;

        int index = 0;
        int length = expression.length();
        while (index < length) {
            int currentNumerator = 0;
            int currentDenominator = 0;
            bool isNegative = (expression[index] == '-');

            if (expression[index] == '+' || expression[index] == '-') {
                index++;
            }

            while (index < length && isdigit(expression[index])) {
                int digit = expression[index] - '0';
                currentNumerator = (currentNumerator * 10) + digit;
                index++;
            }

            index++; 

            if (isNegative) {
                currentNumerator *= -1;
            }

            while (index < length && isdigit(expression[index])) {
                int digit = expression[index] - '0';
                currentDenominator = (currentDenominator * 10) + digit;
                index++;
            }

            numerator = numerator * currentDenominator + currentNumerator * denominator;
            denominator *= currentDenominator;
        }

        int gcd = abs(__gcd(numerator, denominator));

        numerator /= gcd;
        denominator /= gcd;

        return to_string(numerator) + "/" + to_string(denominator);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
