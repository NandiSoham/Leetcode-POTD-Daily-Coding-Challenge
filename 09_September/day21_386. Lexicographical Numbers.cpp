// Problem Link -> https://leetcode.com/problems/lexicographical-numbers/description/

class Solution {
public:

    void helper(int curr, int n, vector<int>& result) {
        if(curr > n) 
            return;
        
        result.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextNum = curr * 10 + nextDigit;
            if(nextNum > n)
                return;
            helper(nextNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        for(int num = 1; num <= 9; num++)
            helper(num, n, result);
        
        return result;
    }
};
