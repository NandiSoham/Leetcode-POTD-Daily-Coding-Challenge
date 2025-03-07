// Problem Link -> https://leetcode.com/problems/closest-prime-numbers-in-range/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    vector<bool> generatePrimeFlags(int right) {
        vector<bool> primeFlags(right + 1, true);

        primeFlags[0] = false;
        primeFlags[1] = false;

        for(int i = 2; i * i <= right; i++) {
            if(primeFlags[i] == true) {
                for(int j = 2; i * j <= right; j++) {
                    primeFlags[i * j] = false;
                }
            }
        }

        return primeFlags;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> primeFlags = generatePrimeFlags(right);

        vector<int> primeNums;
        for(int num = left; num <= right; num++) {
            if(primeFlags[num] == true) {
                primeNums.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> closestPair = {-1, -1};

        for(int i = 1; i < primeNums.size(); i++) {
            int diff = primeNums[i] - primeNums[i - 1];

            if(diff < minDiff) {
                minDiff = diff;
                closestPair = {primeNums[i - 1], primeNums[i]};
            }
        }

        return closestPair;
    }
};



// Time Complexity -> O(Rlog(log(R)) + (R-L))
// SPace Complexity -> O(R)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool checkPrime(int num) {
        if (num == 1) { 
            return false;
        }
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                return false;
            }
        }

        return true;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> primeNums;

        for (int num = left; num <= right; num++) {
            if (checkPrime(num) == true) {
                if (!primeNums.empty() && num - primeNums.back() <= 2) {
                    return {primeNums.back(), num};
                }

                primeNums.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> closestPair = {-1, -1};

        for (int i = 1; i < primeNums.size(); i++) {
            int diff = primeNums[i] - primeNums[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primeNums[i - 1], primeNums[i]};
            }
        }

        return closestPair;
    }
};


// Time Complexity -> O((R-L) * sqrt(R))
// SPace Complexity -> O(R - L)

// =========================================================================================
