// Problem Link -> https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for (int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i - 1] + ((s[i] == '1') ? 1 : 0);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int oneCount =
                    cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i - 1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if ((zeroCount * zeroCount) > oneCount) {
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if ((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else {
                    result += 1;

                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if (next >= n) {
                        result += (n - j - 1);
                        break;
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }
};
