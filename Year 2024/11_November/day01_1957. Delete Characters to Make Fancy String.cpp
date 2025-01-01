// Problem Link -> https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

class Solution {
public:
    string makeFancyString(std::string s) {
        int n = s.length();
        string result = "";
        
        result.push_back(s[0]);
        int freq = 1;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == result.back()) {
                freq++;
                if (freq < 3) {
                    result.push_back(s[i]);
                }
            } else {
                result.push_back(s[i]);
                freq = 1;
            }
        }
        
        return result;
    }
};
