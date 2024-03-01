class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n, '0');
        int i = 0;

        for(char &ch : s){
            if(ch == '1'){
                if(result[n - 1] != '1'){
                    result[n - 1] = '1';
                } else{
                    result[i] = '1';
                    i++;
                }
            }
        }
        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/maximum-odd-binary-number/
