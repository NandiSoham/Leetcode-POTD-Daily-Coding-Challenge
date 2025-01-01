class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";

        for(int i = 0; i < n; i++){
            while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
            }

            if(ans.length() > 0 || num[i] != '0'){
                ans.push_back(num[i]);
            }
        }

        while(ans.length() > 0 && k > 0){
            ans.pop_back();
            k--;
        }

        if(ans == "") return "0";

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n) if we consider auxilary space the string we're using to return the result, otherwise it's O(1)
// Problem Link -> https://leetcode.com/problems/remove-k-digits/description/
