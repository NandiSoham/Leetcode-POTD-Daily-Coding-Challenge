// Problem Link -> https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/

class Solution {
public:
    bool hasSameDigits(string s) {
        string str = "";

        while(s.length() > 2){
            
            for(int i = 0; i < s.length() - 1; i++){
                str.push_back((s[i] + s[i + 1]) % 10);
            }

            s = str;
            str = "";
        }

        return s[0] == s[1];
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(n)
