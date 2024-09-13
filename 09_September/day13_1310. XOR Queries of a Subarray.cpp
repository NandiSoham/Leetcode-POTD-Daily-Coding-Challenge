// Problem Link -> https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumulativeXor(n, 0); 

        cumulativeXor[0] = arr[0];
        for(int i = 1; i < n; i++) { 
            cumulativeXor[i] = cumulativeXor[i - 1] ^ arr[i];
        }

        vector<int> queryResults; 
        for(vector<int>& query : queries) {
            int leftIndex = query[0];
            int rightIndex = query[1];

            int xorValue = cumulativeXor[rightIndex] ^ (leftIndex == 0 ? 0 : cumulativeXor[leftIndex - 1]);

            queryResults.push_back(xorValue); 
        }

        return queryResults;
    }
};



// Time Complexity -> O(n + q)
// SPace Compelxity -> O(n)
