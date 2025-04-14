// Problem Link -> https://leetcode.com/problems/count-good-triplets/description/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size = arr.size();
        int validTripletCount = 0;

        for(int i = 0; i <= size - 3; i++) {
            for(int j = i + 1; j <= size - 2; j++) {

                if(abs(arr[i] - arr[j]) <= a) {
                    
                    for(int k = j + 1; k <= size - 1; k++) {
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            validTripletCount++;
                        }
                    }
                }
            }
        }

        return validTripletCount;
    }
};



// Time Complexity -> O(n ^ 3)
// Space Complexity -> O(1)
