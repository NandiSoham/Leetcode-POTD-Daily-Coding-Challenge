// Problem LInk -> https://leetcode.com/problems/finding-3-digit-even-numbers/description/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> evenNums;
        vector<int> freq(10, 0);

        for (int& digit : digits) {
            freq[digit]++;
        }

        for (int hundreds = 1; hundreds <= 9; hundreds++) {
            if (freq[hundreds] == 0)
                continue;
            freq[hundreds]--;

            for (int tens = 0; tens <= 9; tens++) {
                if (freq[tens] == 0)
                    continue;
                freq[tens]--;

                for (int units = 0; units <= 8; units += 2) {
                    if (freq[units] == 0)
                        continue;
                    freq[units]--;

                    int num = hundreds * 100 + tens * 10 + units;
                    evenNums.push_back(num);
                    freq[units]++;
                }
                freq[tens]++;
            }
            freq[hundreds]++;
        }
        return evenNums;
    }
};



// Time Complexity -> O(n)
// SPace Complexity -> O(1)
