// Probelm Link -> https://leetcode.com/problems/range-product-queries-of-powers/description/

class Solution {
public:
    int mod = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        vector<int> ansArr;

        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                power.push_back(pow(2, i));
            }
        }

        for(auto &it : queries){
            int start = it[0];
            int end = it[1];
            long product = 1;

            for(int i = start; i <= end; i++){
                product = (product * power[i]) % mod;
            }

            ansArr.push_back(product);
        }

        return ansArr;
    }
};


// Time complexity -> O(Q)      [Q = number of qieries]
// Space Complexity -> O(1)
