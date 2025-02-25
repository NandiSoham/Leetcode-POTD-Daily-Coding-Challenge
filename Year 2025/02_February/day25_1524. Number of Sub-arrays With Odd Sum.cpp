// Problem Link -> https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;;
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int currSum = 0;

                for(int k = i; k <= j; k++){
                    currSum += arr[k];
                }

                if(currSum % 2 != 0) count++;
            }
        }

        return count % mod;
    }
};


// Time Complexity ->O(n^3)
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 (better version of Approach -1 ) ====================================

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;;
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++){
            int currSum = 0;

            for (int j = i; j < n; j++){
                currSum += arr[j];
                
                if(currSum % 2 != 0) count++;
            }
        }

        return count % mod;
    }
};


// Time Complexity ->O(n^2)
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;;
        int count = 0;
        int oddCount = 0, evenCount = 1;
        int n = arr.size();
        vector<int> prefixSum(n, 0);

        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        
        for(int i = 0; i < n; i++){
            if(prefixSum[i] % 2 == 0){ //odd + even = odd
                count = (count + oddCount) % mod;
                evenCount++;
            } else { //even + odd = odd
                count = (count + evenCount) % mod;
                oddCount++;
            }
        }

        return count;
    }
};


// Time Complexity ->O(n)
// Space Complexity -> O(n)

// =========================================================================================


// ======================================= Approach - 4 ====================================

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;;
        int count = 0;
        int oddCount = 0, evenCount = 1;
        int n = arr.size();
        int cumSum = 0;
        
        for(int i = 0; i < n; i++){
            cumSum += arr[i];

            if(cumSum % 2 == 0){ //odd + even = odd
                count = (count + oddCount) % mod;
                evenCount++;
            } else { //even + odd = odd
                count = (count + evenCount) % mod;
                oddCount++;
            }
        }

        return count;
    }
};


// Time Complexity ->O(n)
// Space Complexity -> O(1)

// =========================================================================================
