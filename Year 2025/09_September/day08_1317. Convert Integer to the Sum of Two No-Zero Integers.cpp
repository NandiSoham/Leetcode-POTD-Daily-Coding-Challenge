// Problem Link -> https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/

class Solution {
public:
    bool checkZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true; 
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int target) {
        for (int a = 1; a < target; ++a) {
            int b = target - a;
            if (!checkZero(a) && !checkZero(b)) {
                return {a, b};
            }
        }
        return {}; 
    }
};



// Time Complexity -> O(n log n)
// Space complexity -> O(1)
