// Problem Link -> https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int mod = 1e9 + 7;
        const int alphabetSize = 26;

        vector<vector<long long>> transitionMatrix(alphabetSize, vector<long long>(alphabetSize, 0));

        for (int fromChar = 0; fromChar < alphabetSize; ++fromChar) {
            for (int shift = 1; shift <= nums[fromChar]; ++shift) {
                int toChar = (fromChar + shift) % alphabetSize;
                transitionMatrix[fromChar][toChar]++;
            }
        }

        vector<vector<long long>> finalMatrix = raiseMatrixToPower(transitionMatrix, t, mod);

        vector<long long> initialFreq(alphabetSize, 0);
        for (char ch : s) {
            initialFreq[ch - 'a']++;
        }

        long long transformedTotal = 0;

        for (int toChar = 0; toChar < alphabetSize; ++toChar) {
            long long count = 0;
            for (int fromChar = 0; fromChar < alphabetSize; ++fromChar) {
                count = (count + initialFreq[fromChar] * finalMatrix[fromChar][toChar]) % mod;
            }
            transformedTotal = (transformedTotal + count) % mod;
        }

        return transformedTotal;
    }

    vector<vector<long long>> multiplyMatrices(vector<vector<long long>>& A, vector<vector<long long>>& B, int mod) {
        int size = A.size();
        vector<vector<long long>> product(size, vector<long long>(size, 0));

        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0)
                    continue;
                for (int j = 0; j < size; ++j) {
                    product[i][j] = (product[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }

        return product;
    }

    vector<vector<long long>> raiseMatrixToPower(vector<vector<long long>>& matrix, int power, int mod) {
        int size = matrix.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }

        vector<vector<long long>> base = matrix;

        while (power > 0) {
            if (power % 2 == 1) {
                result = multiplyMatrices(result, base, mod);
            }
            base = multiplyMatrices(base, base, mod);
            power /= 2;
        }

        return result;
    }
};



// Time Complexity -> O(N+Log(T))
// Space Complexity -> O(N)
