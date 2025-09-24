// Problem Link -> https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";  

        string ans;

        if ((1LL * numerator * denominator) < 0) ans.push_back('-');

        long long absNumerator = llabs((long long)numerator);
        long long absDenominator = llabs((long long)denominator);

        
        ans += to_string(absNumerator / absDenominator);   // integer division part

        long long rem = absNumerator % absDenominator;
        if (rem == 0) return ans;  

        ans.push_back('.');

        unordered_map<long long, int> seen;

        while (rem) {
            if (seen.count(rem)) {
                ans.insert(seen[rem], "("); 
                ans.push_back(')');        
                break;
            }

            seen[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / absDenominator);
            rem %= absDenominator;
        }

        return ans;
    }
};



// Time Complexity -> O(denominator)
// Space Complexity -> O(denominator)
