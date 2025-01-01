// Problem Link -> https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0); 

        for (int &num : arr) {
            int remainder = (num % k + k) % k; 
            remainderCount[remainder]++;
        }

        if (remainderCount[0] % 2 != 0) {
            return false;
        }

        for (int remainder = 1; remainder <= k / 2; remainder++) {
            int complementRemainder = k - remainder; 
            if (remainderCount[complementRemainder] != remainderCount[remainder]) {
                return false;
            }
        }

        return true;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(k)
