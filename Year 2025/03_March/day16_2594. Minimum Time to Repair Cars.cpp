// Problem Link -> https://leetcode.com/problems/minimum-time-to-repair-cars/description/

class Solution {
public:
    bool canRepairAllCars(vector<int>& ranks, long long mid, int cars){
        long long repairedCras = 0;

        for(int rank : ranks){
            repairedCras += sqrt(mid / rank) ;
        }

        return repairedCras >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int maxRank = *max_element(ranks.begin(), ranks.end());
        long long left = 1;
        long long right = 1LL * maxRank * cars * cars;
        long long minTime = 0;

        while(left <= right){
            long long mid = left + (right - left) / 2;

            if(canRepairAllCars(ranks, mid, cars) == true){
                minTime = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minTime;
    }
};


// Time Complexity -> O(n * log(maxRank * cars * cars)
// Space Complexity -> O(1)
