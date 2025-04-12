// Problem Link -> https://leetcode.com/problems/find-the-count-of-good-integers/description/

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> uniqueDigitPatterns;

        int halfLen = (n + 1) / 2;
        int startNum = pow(10, halfLen - 1);
        int endNum = pow(10, halfLen) - 1;

        for(int num = startNum; num <= endNum; num++) {
            string leftPart = to_string(num);
            string fullPalindrome = "";

            if(n % 2 == 0) {
                string rightPart = leftPart;
                reverse(rightPart.begin(), rightPart.end());
                fullPalindrome = leftPart + rightPart;
            } else {
                string rightPart = leftPart.substr(0, halfLen - 1);
                reverse(rightPart.begin(), rightPart.end());
                fullPalindrome = leftPart + rightPart;
            }

            long long currNum = stoll(fullPalindrome);
            if(currNum % k != 0)
                continue;

            sort(fullPalindrome.begin(), fullPalindrome.end());
            uniqueDigitPatterns.insert(fullPalindrome);
        }

        vector<long long> factorials(11, 1);
        for(int i = 1; i < 11; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        long long totalCount = 0;
        for(const string& sortedDigits : uniqueDigitPatterns) {
            vector<int> digitFrequency(10, 0);
            for(const char& ch : sortedDigits) {
                digitFrequency[ch - '0']++;
            }

            int totalDigits = sortedDigits.length();
            int zeroCount = digitFrequency[0];
            int nonZeroCount = totalDigits - zeroCount;

            long long permutations = nonZeroCount * factorials[totalDigits - 1];
            for(int i = 0; i < 10; i++) {
                permutations /= factorials[digitFrequency[i]];
            }

            totalCount += permutations;
        }

        return totalCount;
    }
};
