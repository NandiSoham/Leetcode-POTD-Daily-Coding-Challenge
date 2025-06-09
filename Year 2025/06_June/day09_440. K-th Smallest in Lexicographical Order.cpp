// Problem Link -> https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

class Solution {
public:
    int getLexicalCount(long prefix, long nextPrefix, int limit) {
        int totalCount = 0;

        while (prefix <= limit) {
            totalCount += (min(nextPrefix, long(limit + 1)) - prefix);
            prefix *= 10; 
            nextPrefix *= 10; 
        }

        return totalCount;
    }

    int findKthNumber(int n, int k) {
        int currNum = 1; 
        k -= 1; 

        while (k > 0) {
            int prefixCount = getLexicalCount(currNum, currNum + 1, n); 

            if (prefixCount <= k) {
                currNum++;
                k -= prefixCount;
            } else {
                currNum *= 10;
                k -= 1; 
            }
        }

        return currNum;
    }
};



// Time Complexity -> O(log² n)
// Space Complexity -> O(1)
