class Solution {
public:
    string makeGood(string s) {
        string resultStr = "";

        for(char &ch : s){
            if(!resultStr.empty() && (resultStr.back() + 32 == ch || resultStr.back() - 32 == ch)){
                resultStr.pop_back();
            } else{
                resultStr.push_back(ch);
            }
        }
        return resultStr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/make-the-string-great/
