// Problem Link -> https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19


class Solution {
public:
    int findBouquetsCount(vector<int>& bloomDay, int midDay, int k) {
        int bouquetCount = 0;
        int consecutiveCount = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= midDay) {
                consecutiveCount++;
            } else
                consecutiveCount = 0;

            if (consecutiveCount == k) {
                bouquetCount++;
                consecutiveCount = 0;
            }
        }
        return bouquetCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int result = -1;
        int startDay = 0;
        int endDay = *max_element(bloomDay.begin(), bloomDay.end());

        while (startDay <= endDay) {
            int midDay = startDay + (endDay - startDay) / 2;
            if (findBouquetsCount(bloomDay, midDay, k) >= m) {
                result = midDay;
                endDay = midDay - 1;
            } else {
                startDay = midDay + 1;
            }
        }

        return result;
    }
};



// Time Complexity -> O(n * log(max_dady)), n is the number of flowers and max_d is the highest value in the array bloomDay.
// Sapce Complexity -> O(1)
