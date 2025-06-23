// Problem Link -> https://leetcode.com/problems/sum-of-k-mirror-numbers/description/

class Solution {
public:

    bool isRevEqual(string &s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    string getBaseK(long long value, int base) {
        if (value == 0) return "0";

        string converted = "";
        while (value > 0) {
            converted += to_string(value % base);
            value /= base;
        }

        return converted;
    }

    long long kMirror(int k, int n) {
        long long total = 0;
        int digits = 1;

        while (n > 0) {
            int prefixLen = (digits + 1) / 2;
            long long start = pow(10, prefixLen - 1);
            long long end = pow(10, prefixLen) - 1;

            for (long long prefix = start; prefix <= end; prefix++) {
                string part1 = to_string(prefix);
                string part2 = part1;
                reverse(part2.begin(), part2.end());

                string candidate;
                if (digits % 2 == 0) {
                    candidate = part1 + part2;
                } else {
                    candidate = part1 + part2.substr(1);
                }

                long long fullNumber = stoll(candidate);
                string baseK = getBaseK(fullNumber, k);

                if (isRevEqual(baseK)) {
                    total += fullNumber;
                    n--;
                    if (n == 0) break;
                }
            }

            digits++;
        }

        return total;
    }
};


