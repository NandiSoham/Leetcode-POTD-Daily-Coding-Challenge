// Problem Link -> https://leetcode.com/problems/count-largest-group/description/

class Solution {
public:
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while(num) {
            digitSum += num % 10;
            num /= 10;
        }

        return digitSum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumFrequency;

        int maxGroupSize = 0;
        int maxGroupCount = 0;

        for(int currNum = 1; currNum <= n; currNum++) {
            int currSum = calculateDigitSum(currNum);

            digitSumFrequency[currSum]++;
            if(digitSumFrequency[currSum] == maxGroupSize) {
                maxGroupCount++;
            } else if(digitSumFrequency[currSum] > maxGroupSize) {
                maxGroupSize = digitSumFrequency[currSum];
                maxGroupCount = 1;
            }
        }

        return maxGroupCount;
    }
};


// tiem Complexity -> O(n logn)
// Spaec Complexity -> O(n)
